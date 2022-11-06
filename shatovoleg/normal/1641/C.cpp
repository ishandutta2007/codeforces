#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll

const int INF = (is_same<int, ll>::value ? 4e18l + 666 : 1e9 + 666);
const ll INFll = 4e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}
 
    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n, q;
    cin >> n >> q;

    vector<int> l(n + 1);
    iota(all(l), 0);
    vector<int> left(n + 1, -1);

    auto GetRoot = [&](auto GetRoot, int i) -> int {
        if (l[i] == i) return i;
        return l[i] = GetRoot(GetRoot, l[i]);
    };

    auto Union = [&](int i, int j) -> bool {
        i = GetRoot(GetRoot, i);
        j = GetRoot(GetRoot, j);
        if (i == j) return false;
        l[i] = j;
        cmax(left[j], left[i]);
        return true;
    };

    auto SegUnion = [&](int i, int j) {
        i = GetRoot(GetRoot, i);
        while (i < j) {
            Union(i, i + 1);
            i = GetRoot(GetRoot, i);
        }
    };

    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (x == 0) {
                SegUnion(l, r);
            } else {
                cmax(left[GetRoot(GetRoot, r)], l);
            }
        } else {
            int idx;
            cin >> idx;
            --idx;
            int u = GetRoot(GetRoot, idx), v = GetRoot(GetRoot, idx + 1);
            if (u == v) {
                cout << "NO\n";
            } else if (left[v] == -1 || GetRoot(GetRoot, left[v]) != u) {
                cout << "N/A\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}