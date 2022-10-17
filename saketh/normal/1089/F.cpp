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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    int sf = -1;
    for (int p = 2; p * p <= N; p++) {
        if (N % p == 0 && __gcd(N / p, p) == 1) {
            sf = p;
            break;
        }
    }

    if (sf == -1) {
        cout << "NO\n";
    } else {
        for (int q = 0; q <= N/sf; q++) {
            int r = N - 1 - (N/sf) * q;
            if (r % sf == 0) {
                cout << "YES\n2\n";
                cout << q << " " << sf << "\n";
                cout << r/sf << " " << N/sf << "\n";
                return 0;
            }
        }
    }

    return 0;
}