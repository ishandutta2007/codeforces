#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5, mod=998244353;

int rl[sz], rr[sz], rv[sz], stp[sz], gop[sz];
bitset <sz> cnt;

int dp[sz];

#define add(x, y) (x+y >= mod ? x+y-mod : x+y)
#define sub(x, y) (x < y ? x-y+mod : x-y)

int main()
{
    int n,k,m;
    cin >> n >> k >> m;
    for(int i=0; i<m; i++) scanf("%d %d %d", &rl[i], &rr[i], &rv[i]);

    ll ans = 1;
    for(int b=0; b<k; b++) {
        for(int i=0; i<m; i++) {
            int l=rl[i], r=rr[i];
            if((1<<b) & rv[i]) gop[l] = max(gop[l], r);
            else stp[l] = !stp[l] ? r : min(r, stp[l]);
        }

        int e=0;
        for(int i=1, j=0; i<=n; i++) {
            j=max(j, gop[i]), gop[i]=0;
            i<=j ? cnt[i]=1 : cnt[i]=0;
            dp[i]=0;
        }

        int x = 1;
        dp[n+1] = !cnt[n];
        for(int i=n, j=n; i; i--) {
            if(!stp[i]) {
                if(!cnt[i]) x = add(x, x);
            }
            else {
                j = min(j, stp[i]);
                x = sub(dp[i+1], dp[j+2]);
                stp[i] = 0;
            }
            if(!cnt[i-1]) dp[i] = add(dp[i], x);
            dp[i] = add(dp[i], dp[i+1]);
        }
        ans *= x;
        ans %= mod;
    }

    if(ans<0) ans+=mod;
    cout << ans;
}