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

    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    int N;
    cin >> N;
    string weather;
    cin >> weather;

    vi prefX(N + 1), prefY(N + 1);
    for (int i = 1; i <= N; i++) {
        char op = weather[i-1];
        prefX[i] = prefX[i-1] + ((op == 'R') ? 1 : (op == 'L' ? -1 : 0));
        prefY[i] = prefY[i-1] + ((op == 'U') ? 1 : (op == 'D' ? -1 : 0));
    }

    ll ans = -1;
    ll lo = 1, hi = LLONG_MAX/4;

    while (lo <= hi) {
        ll mi = (lo + hi) / 2;

        ll totX = (mi / N) * prefX.back() + prefX[mi % N];
        ll totY = (mi / N) * prefY.back() + prefY[mi % N];
        ll dist = abs((X1 + totX) - X2) + abs((Y1 + totY) - Y2);

        if (dist <= mi) {
            ans = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    cout << ans << endl;
    return 0;
}