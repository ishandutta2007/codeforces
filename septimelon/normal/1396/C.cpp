#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const ll INF = 100000000000000000LL;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, r[3], d;
    cin >> n >> r[0] >> r[1] >> r[2] >> d;
    vector<ll> k(n);
    vector<ll> cht(n), fut(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        fut[i] = k[i] * r[0] + r[2];
        cht[i] = min((k[i] + 2LL) * r[0], r[1] + r[0]);
        cht[i] = min(cht[i], fut[i]);
    }

    vector<vector<ll>> mint(4, vector<ll>(n, INF));
    mint[0][0] = fut[0];
    mint[1][0] = cht[0];
    for (int j = 1; j < n; ++j) {
        mint[0][j] = mint[0][j - 1] + fut[j];
        for (ll i = 1; i < 4; ++i) {
            mint[i][j] = min(mint[i][j], mint[i - 1][j - 1] + cht[j]);
            mint[0][j] = min(mint[0][j], mint[i][j - 1] + cht[j] + d * i * 2LL);
        }
    }

    ll ans = mint[0][n - 1];
    for (ll i = 1; i < 4; ++i) {
        ans = min(ans, mint[i][n - 2] + fut[n - 1] + d * i);
        ans = min(ans, mint[i][n - 2] + cht[n - 1] + d * i * 2LL);
    }
    ans += d * (n - 1);

    cout << ans << "\n";

    return 0;
}