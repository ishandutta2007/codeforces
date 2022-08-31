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
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int l[maxn], r[maxn];
vi eg[maxn];
int n;
int ans =0;
int dfs(int a) {
    ll cur = 0;
    for (auto v : eg[a]) 
        cur += dfs(v);
    if (cur > r[a]) cur = r[a];
    if (cur < l[a]) cur = r[a], ans += 1;
    return cur;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            eg[i].clear();
        for (int i = 2; i <= n; i++) {
            int p;
            scanf("%d", &p            );
            eg[p].pb(i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &l[i], &r[i]);
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return (0-0); //<3
}