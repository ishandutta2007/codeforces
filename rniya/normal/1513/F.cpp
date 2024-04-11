#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

/**
 * @brief Segment Tree
 * @docs docs/datastructure/SegmentTree.md
 */
template <typename Monoid> struct SegmentTree {
    typedef function<Monoid(Monoid, Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_, F f, Monoid id) : f(f), id(id) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, id);
    }
    void build(const vector<Monoid>& v) {
        for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
        for (int i = n - 1; i; i--) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
    void update(int k, Monoid x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[k << 1 | 0], dat[k << 1 | 1]);
    }
    Monoid query(int a, int b) {
        if (a >= b) return id;
        Monoid vl = id, vr = id;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
    template <typename C> int find_subtree(int k, const C& check, Monoid& M, bool type) {
        while (k < n) {
            Monoid nxt = type ? f(dat[k << 1 | type], M) : f(M, dat[k << 1 | type]);
            if (check(nxt))
                k = k << 1 | type;
            else
                M = nxt, k = k << 1 | (type ^ 1);
        }
        return k - n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template <typename C> int find_first(int a, const C& check) {
        Monoid L = id;
        if (a <= 0) {
            if (check(f(L, dat[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = n;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, dat[l]);
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template <typename C> int find_last(int b, const C& check) {
        Monoid R = id;
        if (b >= n) {
            if (check(f(dat[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = n;
        for (int l = a, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(dat[--r], R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i) { return dat[i + n]; }
};

/**
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < v.size(); i++) res[v[i]] = i;
    return res;
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;

    vector<int> c;
    for (int& x : a) c.emplace_back(x);
    for (int& x : b) c.emplace_back(x);
    map<int, int> nmp = compress(c);
    map<int, int> mp;
    for (auto& p : nmp) mp[p.second] = p.first;
    ll ans = 0;
    vector<pair<int, int>> u, v;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        a[i] = nmp[a[i]];
        b[i] = nmp[b[i]];
        if (a[i] < b[i]) u.emplace_back(a[i], b[i]);
        if (a[i] > b[i]) v.emplace_back(a[i], b[i]);
    }

    sort(u.rbegin(), u.rend());
    sort(v.begin(), v.end(), [](pair<int, int> p, pair<int, int> q) { return p.second > q.second; });
    int m = mp.size();
    SegmentTree<int> seg1(
        m, [](int a, int b) { return max(a, b); }, 0),
        seg2(
            m, [](int a, int b) { return min(a, b); }, INF);

    int sub = 0;
    multiset<int> s;
    for (auto& p : v) s.emplace(p.first);

    for (int i = 0, j = 0; i < u.size(); i++) {
        int A = u[i].first, B = u[i].second;
        while (j < v.size() && v[j].second > A) {
            int C = v[j].first, D = v[j].second;
            s.erase(s.find(C));
            seg1.update(C, max(seg1[C], mp[C] - mp[D]));
            seg2.update(C, min(seg2[C], mp[D]));
            j++;
        }
        if (!s.empty()) sub = max(sub, mp[min(B, *s.rbegin())] - mp[A]);
        sub = max(sub, seg1.query(0, B + 1));
        sub = max(sub, mp[B] - seg2.query(B, m));
    }

    cout << ans - sub * 2 << '\n';
    return 0;
}