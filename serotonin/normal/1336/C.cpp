#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3005, mod = 998244353;

char s[sz], t[sz];

int ns, nt, dp[sz][sz];

int fnc(int x, int y)
{
    if(x > y) return 1;
    if(dp[x][y] < 0) {
        int now = 0, l = y - x;
        if(x >= nt || t[x] == s[l]) now += fnc(x+1, y);
        if(y >= nt || t[y] == s[l]) now += fnc(x, y-1);
        dp[x][y] = now % mod;
    }
    return dp[x][y];
}

int main()
{
    scanf("%s %s", s, t);
    ns = strlen(s), nt = strlen(t);
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i=nt-1; i<ns; i++) ans += fnc(0, i);
    cout << ans % mod;
}