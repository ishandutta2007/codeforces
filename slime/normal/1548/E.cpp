//
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int d[maxn];
int lb (int x) {
    return x & -x;
}
void ins(int pl, int x) {
    while (pl < maxn) {
        d[pl] += x;
        pl += lb(pl);
    }
}
int q(int a) {
    int ans = 0;
    while (a) {
        ans += d[a]; a -= lb(a);
    }
    return ans;
}
vi u, v;
struct rg {
    int p;
    int l, r; // l >= 1, r < maxn
    rg() {}
};
vector<pi> act[maxn], ask[maxn];
ll wk(vector<rg> a, vector<rg> b) {
    for (auto v : a)
        act[v.p].pb(mp(v.l, v.r));
    for (auto v : b) {
        ask[v.l - 1].pb(mp(v.p, -1));
        ask[v.r].pb(mp(v.p, 1));
    }
    ll ans = 0;
    for (int i = 1; i < maxn; i++) {
        for (auto v : act[i])
            ins(v.fi, 1), ins(v.se + 1, -1);
        for (auto v : ask[i])
            ans += q(v.fi) * v.se;
    }
    return ans;
}
int mx[maxn][20];
int mb[maxn];
int qmx(int l, int r) {
    int len = r - l + 1;
    int j = mb[len];
    return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}
int st[maxn], top = 0;
int n, m, x;
vector<rg> gt(vi a) {
    #define ar3 array<int, 3>
    int n = a.size();
    vector<ar3> tot;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 20; j++)
            if ((1 << j) <= i) mb[i] = j;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < n - (1 << i) + 1; j++) {
            if (i == 0) mx[j][i] = a[j];
            else {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    for (int s = 0; s < 2; s++) {
        int top = 0;
        for (int i = 0; i < n; i++) {
            int cr = maxn;
            while (top && a[st[top - 1]] > a[i]) 
                chkmin(cr, a[st[top - 1]]), top -= 1;
            if (top) {
                int fl = 1;
                if (s == 1 && a[st[top - 1]] == a[i]) fl = 0;               
                if (fl) {
                    if (s == 0) tot.pb((ar3){st[top - 1], i, cr});
                    else tot.pb((ar3){n - 1 - i, n - 1 - st[top - 1], cr});
                }
            }
            st[top++] = i;
        }
        reverse(a.begin(), a.end());
    }
    vector<rg> res;
    for (auto v : tot) {
        int l = v[0], r = v[1], sc = v[2];
        rg fn; fn.l = max(1, x + 1 - sc); fn.r = min(maxn - 1, x - max(a[l], a[r]));
        fn.p = qmx(l, r);
        if (fn.l > fn.r) continue;
        res.pb(fn);
    }
    return res;
}
int fl[maxn];
int sum = 0, s1 = 0;
void inc(int x) {
    fl[x] = 1;
    if (fl[x - 1]) s1 += 1;
    if (fl[x + 1]) s1 += 1;
    sum += 1;
}
int main() {
    cin >> n >> m >> x;
    vi u[2];
    vector<pi> s[2];
    u[0].resize(n), u[1].resize(m);
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < u[t].size(); i++) {
            scanf("%d", &u[t][i]);
            s[t].pb(mp(u[t][i], i + 1));
        }
        sort(s[t].begin(), s[t].end());
    }
    /*
    for (int i = 0; i < u[0].size(); i++) {
        for (int j = 0; j < u[1].size(); j++) {
            if (u[0][i] + u[1][j] <= x) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    */
    ll ans = wk(gt(u[0]), gt(u[1]));
    //cout << ans << endl;
    int pl = 0;
    for (int g = 0; g < 2; g++) {
        sum = s1 = 0; memset(fl, 0, sizeof(fl));
        int p = 0;
        for (int i = s[0].size() - 1; i >= 0; i--) {
            while (p < s[1].size() && s[1][p].fi + s[0][i].fi <= x) {
                inc(s[1][p].se);
                p += 1;
            }
            ans -= s1;
            if (g == 0) ans += sum;
        }
        swap(s[0], s[1]);
    }
    cout << ans << endl;
    return (0-0); //<3
}