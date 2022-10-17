#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int D;
        cin >> D;

        double mp = D/2.;
        double pm = sqrt(D * D - 4. * D)/2;

        double a1 = mp + pm;
        if (a1 > -1e-15 && D - a1 > -1e-15) {
            cout << "Y " << a1 << " " << D - a1 << "\n";
        } else {
            double a2 = mp - pm;
            if (a2 > -1e-15 && D - a2 > -1e-15) {
                cout << "Y " << a2 << " " << D - a2 << "\n";
            } else {
                cout << "N\n";
            }
        }
    }

    return 0;
}