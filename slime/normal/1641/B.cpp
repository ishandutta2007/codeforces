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
int a[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<pi> acts;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ad = 0;
        vi fn;
        int pls = 1;
        vi tot; for (int i = 1; i <= n; i++) tot.pb(a[i]);
        while (tot.size()) {
            vi cur;
            cur.pb(tot[0]);
            int pls;
            for (pls = 1; pls < tot.size(); pls++)
                if (tot[pls] == tot[0]) break;
                else cur.pb(tot[pls]);
            if (pls >= tot.size()) break;
            int i = pls;
            fn.pb(2 * (cur.size()));
            for (int i = 1; i < cur.size(); i++) {
                int v = cur[i];
                acts.pb(mp(ad + i + pls, v));
            }
            ad += 2 * cur.size();
            tot.erase(tot.begin() + pls);
            tot.erase(tot.begin());
            reverse(tot.begin(), tot.begin() + pls - 1);
            pls += 1;
        }
        if (tot.size()) printf("-1\n");
        else {
            printf("%d\n", acts.size());
            for (auto v : acts)
                printf("%d %d\n", v.fi, v.se);
            printf("%d\n", fn.size());
            for (auto v : fn)
                printf("%d\n", v);
        }
    }
    return (0-0); //<3
}
/*
1
6
1 3 1 2 2 3
*/