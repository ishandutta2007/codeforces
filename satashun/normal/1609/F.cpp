//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

const int maxn = TEN(6) + 10;
const ll INF = TEN(18) + 10;
using pli = pair<ll, int>;

int pcnt[maxn];
ll a[maxn];
ll ans;
pli mnr[maxn], mxr[maxn];
int good[maxn];
int cnt_mn1[60], cnt_mx1[60], cnt_mn2[60], cnt_mx2[60];

void slv(int l, int r) {
    if (l + 1 >= r) return;

    int m = (l + r) / 2;
    slv(l, m);
    slv(m, r);

    int nr = r - m;

    {
        pli mn(INF, 0), mx(-INF, 0);
        int pt = 0;

        for (int i = m; i < r; ++i) {
            chmin(mn, mp(a[i], pcnt[i]));
            chmax(mx, mp(a[i], pcnt[i]));
            mnr[pt] = mn, mxr[pt] = mx;
            good[pt + 1] = good[pt] + (mn.se == mx.se);
            pt++;
        }
    }

    int pl = 0, pr = 0;
    //[0,pl),[pl,nr)

    pli mn(INF, 0), mx(-INF, 0);
    memset(cnt_mn1, 0, sizeof(cnt_mn1));
    memset(cnt_mn2, 0, sizeof(cnt_mn2));
    memset(cnt_mx1, 0, sizeof(cnt_mx1));
    memset(cnt_mx2, 0, sizeof(cnt_mx2));

    for (int i = m - 1; i >= l; --i) {
        chmin(mn, mp(a[i], pcnt[i]));
        chmax(mx, mp(a[i], pcnt[i]));
        while (pl < nr && mnr[pl].fi >= mn.fi) {
            cnt_mn1[mnr[pl].se]++;
            cnt_mx1[mxr[pl].se]++;
            ++pl;
        }
        while (pr < nr && mxr[pr].fi <= mx.fi) {
            cnt_mn2[mnr[pr].se]++;
            cnt_mx2[mxr[pr].se]++;
            ++pr;
        }

        if (mn.se == mx.se) {
            ans += min(pl, pr);
        }
        ans += good[nr] - good[max(pl, pr)];
        if (pl <= pr) {
            ans += cnt_mn2[mx.se] - cnt_mn1[mx.se];
            /*
            for (int i = pl; i < pr; ++i) {
                if (mnr[i].se == mx.se) {
                    ans++;
                }
            }*/
        } else {
            ans += cnt_mx1[mn.se] - cnt_mx2[mn.se];
            /*
            for (int i = pr; i < pl; ++i) {
                if (mxr[i].se == mn.se) {
                    ans++;
                }
            }*/
        }
    }
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        pcnt[i] = __builtin_popcountll(a[i]);
    }
    /*
        int c = 0;

        rep(i, n) {
            rep(j, i + 1) {
                int mn = *min_element(a.begin() + j, a.begin() + i + 1);
                int mx = *max_element(a.begin() + j, a.begin() + i + 1);
                if (__builtin_popcount(mn) == __builtin_popcount(mx)) {
                    c++;
                }
            }
        }
        print(c);
    */

    ans = n;

    slv(0, n);
    print(ans);

    return 0;
}