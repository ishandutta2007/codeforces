#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vll app(1 << 18);

    for (int i = 0; i < N; i++) {
        char op;
        cin >> op;

        if (op == '?') {
            string query;
            cin >> query;

            ll qval = 0;
            for (char c : query) {
                qval = (2 * qval) + (c == '1');
            }

            cout << app[qval] << "\n";
        } else {
            ll val;
            cin >> val;

            int diff = (op == '+') ? 1 : -1;
            ll rep = 0, tmp = val;

            for (int l = 0; l < 18; l++) {
                ll bit = (tmp % 10) % 2;
                tmp /= 10;
                rep += bit << l;
            }
            
            app[rep] += diff;
        }
    }

    return 0;
}