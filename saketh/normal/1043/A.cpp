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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int k = 0; true; k++) {
        int opp = 0;
        int my = 0;
        bool ok = true;

        for (int v : a) {
            if (v > k) {
                ok = false;
                break;
            }
            opp += v;
            my += k - v;
        }

        if (ok && my > opp) {
            cout << k << endl;
            return 0;
        }
    }

    return 0;
}