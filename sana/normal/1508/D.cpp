#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

vector<int> par;
int find(int a) {
    if (par[a]==a) return a;
    return par[a]=find(par[a]);
}
 
void link(int a, int b) {
    //printf("link %d %d\n",a,b);
    int x = find(a), y = find(b);
    par[y]=x;
}

struct point {
    long long x, y;
    int id;

    // in point struct
    long long CrossProd(const point &p) const {
      return x * (long long)p.y - y * (long long)p.x;
    }
    bool operator<(const point &p) const {
      if (y != p.y) return y < p.y;
      return x > p.x;
    //   return make_pair(x, y) < make_pair(p.x, p.y);
    }
};

vector<point> a;
vector< pii > ops;
vi label;
void go(int aa, int b) {
    if (aa > b) swap(aa,b);
    ops.emplace_back(aa, b);
    swap(label[aa], label[b]);
}

void pp(int x) {
    cout << a[x].x << " " << a[x].y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    par.resize(n); for (int i = 0; i < n; i++) par[i] = i;

    a = vector<point>(n);
    label = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> label[i];
        a[i].id = i;
        label[i]--;
    }
    
    vi seen(n);
    for (int i = 0; i < n; i++) if (!seen[i]) {
        seen[i] = 1;
        int cur = i;
        do {
            cur = label[cur];
            seen[cur] = 1;
            link(i, cur);
        } while (cur != i);
    }

    int origin_idx = -1;
    for (int i = 0; i < n; i++) if (label[i] != i) origin_idx = i;

    if (origin_idx == -1) {
        cout << 0 << endl;
        return 0;
    }

    vector<point> sorted = a;
    for (int i = 0; i < n; i++) {
        sorted[i].x -= a[origin_idx].x;
        sorted[i].y -= a[origin_idx].y;
    }
    swap(sorted[origin_idx], sorted[n-1]);
    sorted.pop_back();

    sort(sorted.begin(), sorted.end(), [] (point a, point b) {
        const point origin{0,0};
        bool ba = a < origin, bb = b < origin;
        if (ba != bb) { return ba > bb; }
        return a.CrossProd(b) > 0;
    });

    int mdi = -1;
    double md = -1;
    for (int i = 0; i < n-1; i++) {
        dbg(sorted[i].x, sorted[i].y, atan2(sorted[i].y, sorted[i].x));
    }
    for (int i = 0; i < n-1; i++) {
        double diff;
        double ang1 = atan2(sorted[i].y, sorted[i].x);
        double ang2 = atan2(sorted[(i-2+n)%(n-1)].y, sorted[(i-2+n)%(n-1)].x);
        if (i == 0) diff = ang1+4*acos(0) - ang2;
        else diff = ang1-ang2;

        if (diff > md) {
            md = diff;
            mdi = i;
            dbg(md, mdi);
        }
    }
    rotate(sorted.begin(), sorted.begin()+mdi, sorted.end());
    
    for (int i = 0; i < n-1; i++) {
        dbg(sorted[i].x, sorted[i].y, atan2(sorted[i].y, sorted[i].x));
    }

    for (int i = 1; i < n-1; i++) {
        if (find(sorted[i-1].id) != find(sorted[i].id)) {
            go(sorted[i-1].id, sorted[i].id);
            link(sorted[i-1].id, sorted[i].id);
        }
    }

    while (label[origin_idx] != origin_idx) {
        // cerr << "swap origin " << origin_idx << " with " << label[origin_idx] << endl;
        go(label[origin_idx], origin_idx);
    }

    

    cout << sz(ops) << '\n';
    for (auto [a,b]: ops) {
        cout << a+1 << " " << b+1 << '\n';
    }

    return 0;
}