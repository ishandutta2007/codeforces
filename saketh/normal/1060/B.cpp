#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int f(ll arg) {
    if (arg == 0) return 0;
    return arg % 10 + f(arg / 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N;
    cin >> N;

    if (N < 10) {
        cout << N << endl;
        return 0;
    }

    ll a = 9;
    while (10 * a + 9 <= N) {
        a = 10 * a + 9;
    }
    cout << f(a) + f(N - a) << endl;

    return 0;
}