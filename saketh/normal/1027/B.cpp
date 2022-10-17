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

ll solve(ll N, ll x, ll y) {
    ll inx = N * x + y;
    ll offset = (x+y)&1 ? (N * N + 1) / 2 : 0;

    ll px = (y > 0) ? x : x - 1;
    ll py = (y > 0) ? y - 1 : N - 1;
    if (((x + y)&1) == ((px + py)&1))
        return offset + (inx + 1) / 2 + 1;
    else
        return offset + (inx) / 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        cout << solve(N, x-1, y-1) << "\n";
    }

    return 0;
}