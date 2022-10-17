#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool solve() {
    int N, Q;
    cin >> N >> Q;

    vvi l, s;
    for (int q = 0; q < Q; q++) {
        int K;
        cin >> K;
        vi path(K);
        for (int i = 0; i < K; i++)
            cin >> path[i];
        (K >= 500 ? l : s).push_back(path);
    }

    vi inx(N + 1, -1), pref(N + 1, -1);
    auto check = [&](vi &b) {
        int em = INT_MAX;
        for (int i = 0; i < b.size(); i++) {
            if (inx[b[i]] == -1) continue;
            if (inx[b[i]] > em && i && pref[b[i]] != b[i-1])
                return false;
            em = min(em, inx[b[i]]);
        }
        return true;
    };
    auto check_all = [&](vvi &v) {
        for (auto& b : v)
            if (!check(b))
                return false;
        return true;
    };

    for (auto& v : l) {
        for (int i = 0; i < v.size(); i++) {
            inx[v[i]] = i;
            if (i) pref[v[i]] = v[i-1];
        }
        if (!check_all(l)) return false;
        if (!check_all(s)) return false;
        for (int i = 0; i < v.size(); i++) {
            inx[v[i]] = -1;
            if (i) pref[v[i]] = -1;
        }
    }

    vector<vector<array<int, 2>>> app(N + 1);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++)
            app[s[i][j]].push_back({ i, j });
    }

    auto assign = [](int &t, int v) {
        if (t != -1 && t != v) return false;
        t = v;
        return true;
    };

    for (int v = 1; v <= N; v++) {
        for (auto [i, j] : app[v]) {
            for (int k = j + 1; k < s[i].size(); k++) {
                if (!assign(pref[s[i][k]], s[i][k-1]))
                    return false;
            }
        }
        for (auto [i, j] : app[v]) {
            for (int k = j + 1; k < s[i].size(); k++) {
                pref[s[i][k]] = -1;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string res = solve() ? "robot" : "human";
        int r = rng();
        for (char& c : res) {
            if (r&1)
                c += 'A' - 'a';
            r >>= 1;
        }
        cout << res << "\n";
    }

    return 0;
}