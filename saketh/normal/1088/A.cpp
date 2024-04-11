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

    int X;
    cin >> X;

    for (int a = 1; a <= X; a++) {
        for (int b = 1; b <= X; b++) {
            bool ok = true;
            ok &= a % b == 0;
            ok &= a * b > X;
            ok &= a / b < X;

            if (ok) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}