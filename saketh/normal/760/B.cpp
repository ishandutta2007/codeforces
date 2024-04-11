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

ll sum(ll A, ll B) {
    if (A > B) swap(A, B);
    return (A + B) * (B - A + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N, M, K;
    cin >> N >> M >> K;

    M -= N;

    ll left = K - 1;
    ll right = N - K;

    ll ans = 0;
    ll lo = 0, hi = M;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;

        ll need = -mi
                + sum(mi, max(mi - left, 0ll))
                + sum(mi, max(mi - right, 0ll));

        if (need <= M) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << ans + 1 << endl;
    return 0;
}