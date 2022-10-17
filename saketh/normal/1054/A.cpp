#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

    int X, Y, Z, t1, t2, t3;
    cin >> X >> Y >> Z >> t1 >> t2 >> t3;

    int stairs = t1 * abs(X - Y);
    int elev = abs(Z - X) * t2 + 2 * t3 + abs(Y - X) * t2 + t3;

    WATCH(stairs);
    WATCH(elev);

    cout << (stairs < elev ? "NO" : "YES") << endl;

    return 0;
}