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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;

    while (TC--) {
        string s;
        cin >> s;
        int h = 0;
        int n = s.size();
        V<int> vh(n + 1);
        rep(i, n) {
            if (s[i] == '1')
                h++;
            else
                h--;
            vh[i + 1] = h;
        }
        debug(vh);

        map<int, V<int>> pts;

        rep(i, n + 1) { pts[vh[i]].eb(i); }

        map<int, V<int>> tps;
        for (auto& [c, v] : pts) {
            int sz = v.size();

            rep(i, sz - 1) {
                tps[c].pb(vh[v[i]] < vh[v[i] + 1]);
                tps[c].pb(vh[v[i + 1]] < vh[v[i + 1] - 1]);
            }
        }

        for (auto& [c, v] : tps) {
            sort(ALL(v));
            // debug(c, v);
        }

        for (auto& [c, v] : pts) {
            int la = v.back();
            if (la < n) {
                tps[c].pb(vh[la] < vh[la + 1]);
            }
        }

        for (auto& [c, v] : tps) {
            debug(c, v);
        }

        map<int, int> piv;

        string ans;

        int i = 0;
        /*
        while (i < n && !tps.count(vh[i])) {
            ans.pb(s[i]);
            i++;
        }*/
        h = vh[i];
        int ph;

        for (; i < n; ++i) {
            // debug(i, ans);
            /*
            if (!tps.count(h) || piv[h] >= tps[h].size()) {
                auto c = ans.back();
                if (c == '0')
                    ans.pb('1');
                else
                    ans.pb('0');
                swap(h, ph);
                continue;
            }*/
            int x = tps[h][piv[h]];
            piv[h] += 2;
            if (x == 0) {
                ans.pb('0');
                h--;
            } else {
                ans.pb('1');
                h++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}