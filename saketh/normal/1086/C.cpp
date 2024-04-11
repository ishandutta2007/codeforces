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
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int K;
    string s, a, b;
    cin >> K >> s >> a >> b;

    auto get_firsts = [&K](string& s, string& b) {
        vector<array<int, 3>> res;
        vector<vb> seen(K, vb(K, false));
        for (int i = 0; i < s.size(); i++) {
            int sc = s[i] - 'a';
            int bc = b[i] - 'a';
            if (seen[sc][bc]) continue;
            seen[sc][bc] = true;
            res.push_back({ i, sc, bc });
        }
        res.push_back({ int(s.size()), -1, -1 });
        return res;
    };

    auto af = get_firsts(s, a), bf = get_firsts(s, b);

    vi mapping(K), inv(K), fixed(K);
    for (int i = 0; i < K; i++)
        mapping[i] = inv[i] = i;

    auto assign = [&](int sv, int bv) {
        if (sv == -1) return false;
        if (mapping[sv] == bv) {
            fixed[sv] = true;
            return true;
        }
        int tr = inv[bv];
        if (fixed[sv] || fixed[tr]) {
            return false;
        }

        mapping[tr] = mapping[sv];
        inv[mapping[sv]] = tr;
        mapping[sv] = bv;
        inv[bv] = sv;
        fixed[sv] = true;
        return true;
    };

    for (int ad = 0; ad < af.size(); ad++) {
        auto _mapping = mapping, _inv = inv, _fixed = fixed;
        auto [ainx, asv, av] = af[ad];

        for (int bd = 0; bd < bf.size(); bd++) {
            auto [binx, bsv, bv] = bf[bd];

            bool done = false;
            if (binx < ainx && a[binx] < b[binx]) {
                if (ainx == a.size()) done = true;
                else for (int ae = 0; ae < K; ae++) {
                    if (ae > (a[ainx] - 'a') && assign(s[ainx] - 'a', ae)) {
                        done = true; break;
                    }
                }
            }
            if (ainx < binx && b[ainx] > a[ainx]) {
                if (binx == b.size()) done = true;
                else for (int be = 0; be < K; be++) {
                    if (be < (b[binx] - 'a') && assign(s[binx] - 'a', be)) {
                        done = true; break;
                    }
                }
            }
            if (ainx == binx) {
                if (ainx == a.size()) done = true;
                else for (int ec = 0; ec < K; ec++) {
                    if ((a[ainx] - 'a') < ec && ec < (b[binx] - 'a') && assign(s[ainx] - 'a', ec)) {
                        done = true; break;
                    }
                }
            }

            if (done) {
                cout << "YES\n";
                for (int v : mapping)
                    cout << char('a' + v);
                cout << "\n";
                return;
            }

            if (!assign(bsv, bv)) break;
        }

        mapping = _mapping, inv = _inv, fixed = _fixed;
        if (!assign(asv, av)) break;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}