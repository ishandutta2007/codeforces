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

    ll K, A, B;
    cin >> K >> A >> B;

    ll wA = A / K,
       wB = B / K;

    // A didn't win all, but B didn't win any??
    if (A % K > 0 && wB == 0) {
        cout << -1 << endl;
        return 0;
    }

    // B didn't win all, but A didn't win any??
    if (B % K > 0 && wA == 0) {
        cout << -1 << endl;
        return 0;
    }

    // Now it's always possible
    cout << wA + wB << endl;

    return 0;
}