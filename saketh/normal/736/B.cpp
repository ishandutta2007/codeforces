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

bool isPrime(ll arg) {
    for (ll v = 2; v * v <= arg; v++)
        if (arg % v == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N;
    cin >> N;

    if (isPrime(N)) {
        cout << 1 << "\n";
    } else if (N % 2 == 0) {
        cout << 2 << "\n";
    } else if (isPrime(N - 2)) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }

    return 0;
}