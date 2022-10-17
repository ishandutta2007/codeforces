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

bool isprime(ll arg) {
    for (int i = 2; i < min(arg - 1, 1000000ll); i++) {
        if (arg % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll A, B;
        cin >> A >> B;

        if (A - B > 1) {
            cout << "NO\n";
            continue;
        }

        cout << (isprime(A + B) ? "YES" : "NO") << "\n";
    }

    return 0;
}