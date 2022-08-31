//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define maxn 1200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
int t, n;
int s[maxn];
ll sum[maxn];
int dp[maxn];
int d[maxn];
int ls[maxn];
int lb(int a) {
    return a & -a;
}
void upd(int a, int b) {
    while (a < maxn) {
        chkmax(d[a], b);
        a += lb(a);
    }
}
int q(int a) {
    int ans = -maxn;
    while (a > 0) {
        chkmax(ans, d[a]);
        a -= lb(a);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]), 
            sum[i] = sum[i - 1] + s[i];
        for (int i = 1; i <= n; i++)
            d[i] = 0, dp[i] = 0;
        vector<ll> cur;
        for (int i = 0; i <= n; i++)
            cur.pb(sum[i]);
        sort(cur.begin(), cur.end());
        for (int i = 0; i <= n; i++) 
            sum[i] = lower_bound(cur.begin(), cur.end(), sum[i]) - cur.begin() + 1;
        for (int i = 1; i <= n + 5; i++)
            dp[i] = -maxn, ls[i] = -1, d[i] = -maxn;
        for (int i = 0; i <= n; i++) {
            if (i) {
                dp[i] = dp[i - 1];
                if (s[i] < 0) dp[i] -= 1;
                chkmax(dp[i], q(sum[i] - 1) + i);
                if (ls[sum[i]] != -1)
                    chkmax(dp[i], dp[ls[sum[i]]]);
            }
            upd(sum[i], dp[i] - i);
            ls[sum[i]] = i;
        }
        printf("%d\n", dp[n]);
    }
    return (0-0); //<3
}