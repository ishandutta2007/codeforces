#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const string vowels = "aeiou";
    vi vow(256, -1);
    for (int i = 0; i < sz(vowels); i++)
        vow[vowels[i]] = i;

    int N;
    cin >> N;
    vector<string> words(N);

    vector<array<int, 3>> have, still;

    for (int i = 0; i < N; i++) {
        cin >> words[i];

        int vc = 0, lv = -1;
        for (char c : words[i]) if (vow[c] != -1) {
            vc++;
            lv = vow[c];
        }

        assert(lv != -1);
        have.push_back({ vc, lv, i });
    }
    sort(all(have));

    vector<array<int, 2>> X, Y;

    for (int i = 0; i < sz(have); i++) {
        if (i+1 < sz(have) && (have[i][0] == have[i+1][0]) && (have[i][1] == have[i+1][1])) {
            X.push_back({ have[i][2], have[i+1][2] });
            i++;
        } else {
            still.push_back(have[i]);
        }
    }

    for (int i = 0; i < sz(still); i++) {
        if (i+1 < sz(still) && still[i][0] == still[i+1][0]) {
            Y.push_back({ still[i][2], still[i+1][2] });
            i++;
        }
    }

    int ans = min(sz(X), (sz(X) + sz(Y)) / 2);
    cout << ans << "\n";

    for (int i = 0; i < min(sz(X), sz(Y)); i++) {
        cout << words[Y[i][0]] << " " << words[X[i][0]] << "\n";
        cout << words[Y[i][1]] << " " << words[X[i][1]] << "\n";
    }

    for (int i = min(sz(X), sz(Y)); i + 1 < sz(X); i += 2) {
        cout << words[X[i+1][0]] << " " << words[X[i][0]] << "\n";
        cout << words[X[i+1][1]] << " " << words[X[i][1]] << "\n";
    }

    return 0;
}