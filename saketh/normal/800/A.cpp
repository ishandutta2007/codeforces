#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N; 
    ll P;
    cin >> N >> P;

    ll as = 0, bs = 0;
    vll a(N), b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        as += a[i];
        bs += b[i];
    }

    if (as <= P) {
        cout << -1 << endl;
        return 0;
    }


    double lo = 0, hi = double(bs) / (as - P);

    for (int r = 0; r < 200; r++) {
        double test = (lo + hi) / 2;
        double charge = 0;

        for (int i = 0; i < N; i++) {
            double need = max(a[i] * test - b[i], 0.);
            charge += need / P;
        }

        if (charge > test) {
            hi = test;
        } else {
            lo = test;
        }
    }

    cout << (lo + hi) / 2 << endl;
    return 0;
}