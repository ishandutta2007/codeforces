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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string str;
        cin >> str;

        bool ok = false;
        for (int i = 0; i < str.size(); i++) {
            int j = str.size() - 1 - i;
            if (i == j) continue;

            if (str[i] != str[j]) {
                ok = true;
                break;
            }

            int sw = -1;
            for (int k = 0; k < str.size(); k++) {
                if (k != i && k != j && str[k] != str[j]) {
                    sw = k;
                    break;
                }
            }
            if (sw != -1) {
                swap(str[j], str[sw]);
                ok = true;
                break;
            }
        }

        if (ok)
            cout << str << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}