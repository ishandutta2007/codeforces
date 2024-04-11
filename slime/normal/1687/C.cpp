//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int a[maxn];
ll s[maxn];
vi eg[maxn];
int fa[maxn];
int gfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = gfa(fa[x]);
}
void cov(int l, int r) {
    void cov(int t);
    int cur = gfa(l);
    while (cur <= r) {
        cov(cur);
        cur = gfa(cur);
    }
}
void cov(int t) {
    s[t] = 0;
    fa[t] = t + 1;
    for (auto v : eg[t]) {
        if (s[v] == 0) {
            cov(min(v, t), max(v, t));
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            a[i] -= x;
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 0; i <= n + 1; i++)
            fa[i] = i, eg[i].clear();
        for (int i = 1; i <= m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            l -= 1;
            eg[l].pb(r);
            eg[r].pb(l);
        }
        for (int i = 0; i <= n; i++)
            if (s[i] == 0) cov(i);
        int flag = 1;
        for (int i = 0; i <= n; i++)
            if (s[i]) flag = 0;
        if (flag) printf("YES\n");
        else printf("NO\n");
                
    }
    return (0-0); //<3
}