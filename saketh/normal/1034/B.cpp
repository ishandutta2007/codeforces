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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

array<ll, 3> par(ll N) {
    array<ll, 3> res = { N/3, N/3, N/3 };
    for (int rem = 1; rem <= N % 3; rem++)
        res[rem]++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N, M;
    cin >> N >> M;

    if (N > M) {
        swap(N, M);
    }

    auto fin = [](ll ans) {
        cout << ans << endl;
        exit(0);
    };

    if (N == 1) {
        array<ll, 3> par = { M/3, M/3, M/3 };
        for (int p = 1; p <= M % 3; p++)
            par[p]++;
        ll ans = 0;
        for (int p = 0; p < 3; p++) {
            ans += par[p] / 2 * 2;
        }
        fin(ans);
    }
    if (N == 2) {
        if (M == 2) fin(0);
        if (M == 3) fin(4);
        if (M == 7) fin(12);
    }

    fin(N * M / 2 * 2);
    return 0;
}