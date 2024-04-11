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
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
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

struct Trie {
    V<int> value;
    int sz;
    Trie* next[2];
    Trie() {
        sz = 0;
        fill(next, next + 2, nullptr);
    }
};

Trie* ins(const string& t, Trie* r, int id) {
    debug(t, id);
    for (int i = 0; i < t.size(); ++i) {
        r->sz++;
        char c = t[i] - '0';
        if (!r->next[c]) r->next[c] = new Trie;
        r = r->next[c];
    }
    r->value.pb(id);
    r->sz++;
    return r;
}

Trie* find(const string& t, Trie* r) {
    for (int i = 0; i < t.size(); ++i) {
        char c = t[i] - '0';
        if (!r->next[c]) r->next[c] = new Trie;
        r = r->next[c];
    }
    return r;
}

int main() {
    int N;
    scanf("%d", &N);
    V<int> A(N), P(N);
    rep(i, N) scanf("%d", &A[i]);
    rep(i, N) scanf("%d", &P[i]);

    auto r = new Trie();

    rep(i, N) {
        string a(30, ' ');
        rep(j, 30) a[j] = '0' + (P[i] >> j & 1);
        reverse(ALL(a));
        ins(a, r, i);
    }
    V<int> ans(N);

    rep(i, N) {
        auto cur = r;
        V<Trie*> vis;
        vis.pb(cur);

        for (int j = 29; j >= 0; --j) {
            bool t = (A[i] >> j) & 1;
            if (!cur->next[t] || cur->next[t]->sz == 0) {
                cur = cur->next[t ^ 1];
            } else {
                cur = cur->next[t];
            }
            vis.pb(cur);
        }
        ans[i] = cur->value.back();
        cur->value.pop_back();
        for (auto p : vis) {
            p->sz--;
        }
    }
    rep(i, N) { printf("%d%c", A[i] ^ P[ans[i]], i == N - 1 ? '\n' : ' '); }
    return 0;
}