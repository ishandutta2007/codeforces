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

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi succ(N);
    for (int i = 0; i < N; i++) {
        cin >> succ[i];
        succ[i]--;
    }

    ll ans = 1;

    for (int i = 0; i < N; i++) {
        int len = 1;
        int loc = succ[i];

        while (loc != i && len < 150) {
            len++;
            loc = succ[loc];
        }

        if (len > 105) {
            cout << -1 << endl;
            return 0;
        }

        if (len % 2 == 0) len /= 2;
        ans = lcm(ans, len);
    }

    cout << ans << endl;
    return 0;
}