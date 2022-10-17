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

    int A, B, N;
    cin >> A >> B >> N;

    double ans = DBL_MAX;

    for (int i = 0; i < N; i++) {
        int X, Y, V;
        cin >> X >> Y >> V;

        double dist = sqrt(pow(X - A, 2) + pow(Y - B, 2));
        ans = min(ans, dist / V);
    }

    cout << ans << "\n";
    return 0;
}