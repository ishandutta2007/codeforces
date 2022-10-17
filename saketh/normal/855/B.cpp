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
    ll P, Q, R;
    cin >> N >> P >> Q >> R;

    vll vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    ll RB = vals.back() * R,
       QRB = vals.back() * (Q + R),
       PQRB = vals.back() * (P + Q + R);

    for (int i = N - 2; i >= 0; i--) {
        RB = max(RB, vals[i] * R);
        QRB = max(QRB, vals[i] * Q + RB);
        PQRB = max(PQRB, vals[i] * P + QRB);
    }

    cout << PQRB << endl;
    return 0;
}