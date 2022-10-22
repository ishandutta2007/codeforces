#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

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
void chmin(T &t, const U &u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T &t, const U &u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
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

bool e[1010][1010];

int main() {
    int n;
    cin >> n;

    set<pii> st;
    st.insert(mp(0, -2));
    st.insert(mp(0, n * 2));

    rep(i, n) {
        st.insert(mp(0, i * 2 - 1));
        st.insert(mp(0, i * 2));
        st.insert(mp(0, i * 2 + 1));
        st.insert(mp(1, i * 2));
        st.insert(mp(2, i * 2));
        st.insert(mp(-1, i * 2));
        st.insert(mp(-2, i * 2));
    }

    V<pii> cand;
    for (int i = -2; i < n * 2; ++i) {
        cand.eb(2, i);
    }
    for (int i = 2; i > -2; --i) {
        cand.eb(i, n * 2);
    }

    for (int i = n * 2; i > -2; --i) {
        cand.eb(-2, i);
    }
    for (int i = -2; i < 2; ++i) {
        cand.eb(i, -2);
    }

    V<pii> vec;
    rep(i, n) { vec.eb(2, i * 2); }
    vec.eb(0, n * 2);
    per(i, n) vec.eb(-2, i * 2);
    vec.eb(0, -2);

    rep(i, vec.size() / 2) {
        pii a = vec[i * 2], b = vec[i * 2 + 1];
        int p = find(ALL(cand), a) - cand.begin();
        while (cand[p] != b) {
            st.insert(cand[p]);
            p++;
            if (p == cand.size()) p = 0;
        }
    }

    cout << st.size() << endl;
    for (auto p : st) {
        cout << p.fi << ' ' << p.se << '\n';
    }

    return 0;
}