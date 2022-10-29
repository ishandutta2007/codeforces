#include <bits/stdc++.h>

using namespace std;

#ifdef SG
    #include <debug.h>
#else 
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Seg
{
    int l, r;
    ll len, min_v, max_v;
    int id;
    void input(int i)
    {
        id = i;
        cin >> l >> r;
        min_v = l;
        max_v = r;
        len = max_v - min_v;
    }
};

bool
cmp_l(const Seg &a, const Seg &b)
{
    return a.l < b.l;
}

bool
cmp_r(const Seg &a, const Seg &b)
{
    return a.r > b.r;
}

bool
cmp_q(const Seg &a, const Seg &b)
{
    return a.r < b.r || (a.r == b.r && a.id > b.id);
}

int n, m;
ve< Seg > rule, channel;
ve< ll > cost;

ve< ll > tree;

int curk;

void
upd(int pos, ll val)
{
    pos += curk;
    umx(tree[pos], val);
    do {
        pos /= 2;
        tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
    } while (pos != 1);
}

ll
get(int l, int r)
{
    ll res = 0ll;
    l += curk;
    r += curk;
    while (l < r) {
        umx(res, max(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) umx(res, tree[l]);
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
    cin >> n >> m;
    vi coord;
    rule.resize(n);
    forn(i, n) {
        rule[i].input(i);
        coord.pb(rule[i].min_v);
        coord.pb(rule[i].max_v);
    }
    channel.resize(m);
    cost.resize(m);
    forn(j, m) {
        channel[j].input(-j - 1);
        cin >> cost[j];
        coord.pb(channel[j].min_v);
        coord.pb(channel[j].max_v);
    }
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    forn(i, n) {
        rule[i].l = lower_bound(all(coord), rule[i].l) - coord.begin();
        rule[i].r = lower_bound(all(coord), rule[i].r) - coord.begin();
    }
    forn(j, m) {
        channel[j].l = lower_bound(all(coord), channel[j].l) - coord.begin();
        channel[j].r = lower_bound(all(coord), channel[j].r) - coord.begin();
    }
    int cnt = sz(coord);
    ve< ll > min_left(cnt + 1, 1000000000ll), max_right(cnt + 1, -1000000000ll);
    sort(all(rule), cmp_r);
    forn(i, n) {
        ll val = rule[i].min_v;
        umn(min_left[rule[i].r], val);
    }
    for (int i = cnt - 1; i >= 0; --i) {
        umn(min_left[i], min_left[i + 1]);
    }
    sort(all(rule), cmp_l);
    forn(i, n) {
        ll val = rule[i].max_v;
        umx(max_right[rule[i].l + 1], val);
    }
    for (int i = 1; i <= cnt; ++i) {
        umx(max_right[i], max_right[i - 1]);
    }
    ve< ll > ans(m, 0ll);
    forn(j, m) {
        int id = -channel[j].id - 1;
        ll left_b = max(channel[j].min_v, min_left[channel[j].r]);
        umx(ans[id], channel[j].max_v - left_b);
        ll right_b = min(channel[j].max_v, max_right[channel[j].l + 1]);
        umx(ans[id], right_b - channel[j].min_v);
    }
    curk = 2;
    while (curk < cnt) curk *= 2;
    tree.assign(2 * curk, 0);
    ve< Seg > query = rule;
    query.insert(query.end(), all(channel));
    sort(all(query), cmp_q);
    for (const auto &val : query) {
        if (val.id >= 0) { // ads
            upd(val.l, val.len);
        } else { // channel
            int id = -val.id - 1;
            umx(ans[id], get(val.l, curk - 1));
        }
    }
    forn(j, m) {
        ans[j] *= cost[j];
    }
    auto elem = max_element(all(ans));
    if (*elem != 0ll) {
        int opt_j = elem - ans.begin(), opt_i = -1;
        int j_id = 0;
        while (-channel[j_id].id - 1 != opt_j) {
            ++j_id;
        }
        forn(i, n) {
            ll diff = min(rule[i].max_v, channel[j_id].max_v) - 
                max(rule[i].min_v, channel[j_id].min_v);
            if (*elem == diff * cost[opt_j]) {
                opt_i = rule[i].id;
                break;
            }
        }
        cout << *elem << '\n';
        cout << opt_i + 1 << ' ' << opt_j + 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}