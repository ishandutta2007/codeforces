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

    ll N, K, S;
    cin >> N >> K >> S;

    ll mini = K;
    ll maxi = (N - 1) * K;

    if (S < mini || maxi < S) {
        cout << "NO\n";
        return 0;
    }

    ll each = S / K;
    ll extra = S % K;

    cout << "YES\n";
    ll loc = 1;
    for (int i = 0; i < K; i++) {
        ll move = (i < extra) ? each + 1 : each;
        if (loc - move >= 1) {
            loc -= move;
        } else {
            loc += move;
        }
        cout << loc << " ";
    }

    cout << endl;
    return 0;
}