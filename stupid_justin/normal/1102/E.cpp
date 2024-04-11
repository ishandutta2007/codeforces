#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    map<int, int> lst;
    vector<int> last_pos(n);
    for(int i = n - 1; i >= 0; i--)
    {
        if(!lst.count(a[i]))
            lst[a[i]] = i;
        last_pos[i] = lst[a[i]];
    }
    int ans = 1;
    int cur_max = -1;
    for(int i = 0; i < n - 1; i++)
    {
        cur_max = max(cur_max, last_pos[i]);
        if(cur_max == i)
            ans = (2 * ans) % MOD;
    }   
    printf("%d\n", ans);
    return 0;
}