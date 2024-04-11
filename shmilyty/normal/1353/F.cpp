#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clean(a , b) memset(a , b , sizeof(a))
#define rep(i , l , r) for (int i = (l); i <= (r); i ++)
#define per(i , r , l) for (int i = (r); i >= (l); i --)
using namespace std;
const int N = 10001;
const int M = 100001;
const int HA = 998244353;
const int INF = 2147483647;
const long long INFL = 9023372036854775801;
ll a[101][101] , f[101][101];
ll solve(ll n , ll m , ll sta)
{
    rep(i , 1 , n)
        rep(j , 1 , m)
            f[i][j] = INFL;
    f[1][1] = 0;
    rep(i , 1 , n)
        rep(j , 1 , m)
        {
            ll val = i + j + sta;
            if(val > a[i][j])
            {
                f[i][j] = INFL;
                continue;
            }
            f[i][j] += a[i][j] - val;
            if(i + 1 <= n)
                f[i + 1][j] = min(f[i + 1][j] , f[i][j]);
            if(j + 1 <= m)
                f[i][j + 1] = min(f[i][j + 1] , f[i][j]);
        }
    return f[n][m];
}

int main()
{
    ll t , n , m;
    scanf("%lld" , &t);
    while(t --)
    {
        clean(a , 0);
        scanf("%lld%lld" , &n , &m);
        rep(i , 1 , n)
            rep(j , 1 , m)
                scanf("%lld" , &a[i][j]);
        ll ans = INFL;
        rep(i , 1 , n)
            rep(j , 1 , m)
                ans = min(ans , solve(n , m , a[i][j] - i - j));
        printf("%lld\n" , ans);
    }
    return 0;
}