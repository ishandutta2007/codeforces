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
    string str;
    cin >> str;

    vector<char> elt;
    vi ct(26);

    for (char c : str) {
        elt.push_back(c);
        ct[c - 'a']++;
    }

    sort(all(elt));
    elt.erase(unique(all(elt)), elt.end());

    if (elt.size() <= 4) {
        do {
            bool ok = true;
            for (int i = 1; i < elt.size(); i++)
                ok &= abs(elt[i] - elt[i-1]) != 1;
            if (ok) {
                for (char c : elt) {
                    for (int i = 0; i < ct[c - 'a']; i++)
                        cout << c;
                }
                cout << "\n";
                return;
            }
        } while (next_permutation(all(elt)));

        cout << "No answer\n";
        return;
    }

    for (int r = 1; r >= 0; r--) {
        for (int i = r; i < elt.size(); i += 2)
            for (int j = 0; j < ct[elt[i] - 'a']; j++)
                cout << elt[i];
    }
    cout << "\n";
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