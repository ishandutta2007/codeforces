#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NICO = 300000 + 10;
int a, b, c;
int m, kind[NICO];
ll cost[NICO];char s[10];
vector<ll> vec1, vec2, vec;
int main()
{
    cin >> a >> b >> c;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> cost[i];
        scanf("%s",s);
        if(s[0] == 'U')
        {
            vec1.push_back(cost[i]);
        } else {
            vec2.push_back(cost[i]);
        }
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    ll res = 0;int cnt = 0;
    int a1 = min(a, (int)vec1.size());
    int b1 = min(b, (int)vec2.size());
    for(int i=0;i<a1;i++)
    {
        res += vec1[i];cnt ++;
    }
    for(int i=0;i<b1;i++)
    {
        res += vec2[i];cnt ++;
    }
    for(int i=a1;i<vec1.size();i++)
    {
        vec.push_back(vec1[i]);
    }
    for(int i=b1;i<vec2.size();i++)
    {
        vec.push_back(vec2[i]);
    }
    sort(vec.begin(),vec.end());
    int c1 = min(c, (int)vec.size());
    for(int i=0;i<c1;i++)
    {
        res += vec[i];cnt ++;
    }
    cout << cnt << " " << res << endl;
}