//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<ll, ll>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int N = 30000005;
const int maxn = 100005;

int ch[N][2];
int id[N];
int n;
ll l[maxn], r[maxn];
int tp[maxn];
int fa[N];
int gfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = gfa(fa[x]);
}
int u;
int cnt = 0;
set<pair<ll, int> > uu; 
int fid(ll x) {
    auto h = uu.lower_bound(mp(x + 1, 0));
    h--;
    return (*h).se;
}
int rt = 1;
int trcnt = 1;
void ins(ll a, int sz, int ids) {
    int pl = rt;
    for (int m = u - 1; m >= sz; m--) {
        int cr = (a >> m) & 1;
        if (!ch[pl][cr]) ch[pl][cr] = ++trcnt;
        pl = ch[pl][cr];
    }
    assert(trcnt < N * 2 / 3);
    id[pl] = ids;
}
void lk(int a, int b) {
    if (gfa(a) == gfa(b)) return;
    //cout << "LK " << a << ' ' << b << endl;
    fa[gfa(a)] = gfa(b);
}
void lk_all(int pl, int ids) {
    if (!pl) return ;
    if (id[pl]) {
        lk(id[pl], ids);
        return ;
    }
    for (int i = 0; i < 2; i++)
        lk_all(ch[pl][i], ids);
}
void push_seg(ll a, int sz) {
    // a ~ (a + (1 << sz) - 1)
    cnt += 1;
    //cout << "ADE_SEG" << a << ' ' << sz << ' ' << cnt << endl;
    ins(a, sz, cnt);
    uu.insert(mp(a, cnt));
    fa[cnt] = cnt;
    for (int m = u - 1; m >= sz; m--) {
        // m  
        int pl = rt;
        for (int j = u - 1; j >= sz; j--) {
            int cr = (a >> j) & 1;
            if (j == m) cr ^= 1;
            if (!ch[pl][cr]) {
                pl = 0;
                break;
            }
            pl = ch[pl][cr];
            if (id[pl]) {
            //    cout << "???" << m << ' ' << j << ' ' << pl << endl;
                lk(cnt, id[pl]);
                break;
            }
        }
        if (pl) lk_all(pl, cnt);
    }
}
void add(ll l, ll r) {
    #define vl vector<ll>
    //cout << "ADE " << l << ' ' << r << endl;
    vl cr = {0};
    for (int i = u - 1; i >= 0; i--) {
        vl ed;
        for (auto v : cr) {
            ed.pb(v); ed.pb(v + (1ll << i));
        }
        vl ted;
        for (auto v : ed) {
            if (v > r || v + (1ll << i) - 1 < l) continue;
            if (v >= l && (v + (1ll << i) - 1) <= r) push_seg(v, i);
            else ted.pb(v);
        }
        cr = ted;
    }
}
int ans[maxn];
#undef int 
int main() {
    #define int long long
    cin >> u >> n;
    vector<pair<ll, ll> >  de;
    for (int i = 1; i <= n; i++) {
        char inp[5];
        scanf("%s", inp);
        scanf("%lld%lld", &l[i], &r[i]);
        if (inp[0] == 'b') de.pb(mp(l[i], r[i])), tp[i] = 0;
        else tp[i] = 1;
    }
    sort(de.begin(), de.end());
    ll ls = 0;
    for (auto h : de) {
        if (ls < h.fi) add(ls, h.fi - 1);
        chkmax(ls, h.se + 1);
    }
    if (ls < (1ll << u))
        add(ls, (1ll << u) - 1);
    for (int i = n; i >= 1; i--) {
        if (tp[i] == 1) {
            int uf = fid(l[i]), vf = fid(r[i]);
            //cout << "ASK" << uf << ' ' << vf << ' ' << l[i] << ' ' << r[i] << endl;
            if (gfa(uf) == gfa(vf)) ans[i] = 1;
            else ans[i] = 0;
        }
        else add(l[i], r[i]);
    }
    for (int i = 1; i <= n; i++)
        if (tp[i] == 1) printf("%d\n", ans[i]);
    return (0-0); //<3
}