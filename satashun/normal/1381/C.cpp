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

void check(int n, V<int> b, V<int> ans, int gx, int gy) {
    V<int> cnt1(n + 1), cnt2(n + 1);
    int x = 0, y = 0;
    rep(i, n) {
        if (b[i] == ans[i]) {
            ++x;
        } else {
            cnt1[b[i]]++;
            cnt2[ans[i]]++;
        }
    }
    rep(i, n + 1) y += min(cnt1[i], cnt2[i]);
    debug(x, y, gx, gy);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--) {
        int n, x, y;
        cin >> n >> x >> y;

        y -= x;
        V<int> b(n), ans(n, -1), c(n + 1);
        rep(i, n) cin >> b[i], --b[i], ++c[b[i]];
        int unused = -1;
        rep(i, n + 1) if (!c[i]) unused = i;
        debug(x, y, b, unused);

        priority_queue<pii> que;
        V<set<int>> ind(n + 1);
        rep(i, n) ind[b[i]].insert(i);
        rep(i, n + 1) que.emplace(c[i], i);

        rep(_, x) {
            pii p = que.top();
            que.pop();
            int col = p.se;
            --c[col];
            int pos = *ind[col].begin();
            ind[col].erase(pos);
            ans[pos] = col;
            que.emplace(c[col], col);
        }

        debug(c);
        V<int> ins;
        int mx = -1;

        rep(i, n + 1) {
            for (int p : ind[i]) ins.pb(p);
            chmax(mx, (int)ind[i].size());
        }

        auto ous = ins;
        debug(mx);

        rotate(ous.begin(), ous.begin() + mx, ous.end());
        debug(ins, ous);
        int rem = y;
        rep(i, ins.size()) {
            int p = ins[i], q = ous[i];
            if (b[p] == b[q] || rem == 0) continue;
            --rem;
            ans[p] = b[q];
        }

        if (rem > 0) {
            cout << "NO\n";
            continue;
        }
        for (int& v : ans)
            if (v == -1) v = unused;

        cout << "YES\n";
        for (int v : ans) cout << v + 1 << ' ';
        cout << '\n';
        check(n, b, ans, x, y);
    }
    return 0;
}