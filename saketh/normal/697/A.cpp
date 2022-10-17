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

    int T, S, X;
    cin >> T >> S >> X;

    if (X < T) {
        cout << "NO\n";
    } else if (X == T) {
        cout << "YES\n";
    } else if (X < T + S) {
        cout << "NO\n";
    } else {
        int diff = X - T;
        diff %= S;

        if (diff < 2) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}