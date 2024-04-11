#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int NICO = 300000+10;
const int INF = -(1e9 + 7);
int n, x, y, a[NICO], us[NICO], flag[NICO];
vector<int> v[NICO];
multiset<int> s;
int main()
{
    scanf("%d", &n);
    int mx = INF, pos = -1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        a[i] += 2;
        s.insert(a[i]);
    }
    int mac = *s.rbegin();
    for(int i=1;i<n;i++)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = -INF;
    for(int i=1;i<=n;i++)
    {
        int val = a[i] - 2;
        s.erase(s.find(a[i]));
        for(int j=0;j<v[i].size();j++)
        {
            val = max(val, a[v[i][j]] - 1);
            s.erase(s.find(a[v[i][j]]));
        }
        if(!s.empty()) val = max(val, *s.rbegin());
        s.insert(a[i]);
        for(int j=0;j<v[i].size();j++)
        {
            s.insert(a[v[i][j]]);
        }
        ans = min(ans, val);
    }
    printf("%d\n", ans);
}