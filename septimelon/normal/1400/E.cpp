#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1000000000000000LL;
const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll getm(ll del, int l, int r, const vector<ll>& a) {
    if (r - l <= 0) {
        return 0LL;
    }
    
    ll mina = INF;
    for (int i = l; i < r; ++i) {
        mina = min(mina, a[i] - del);
    }

    vector<int> inds;
    inds.push_back(l - 1);
    for (int i = l; i < r; ++i) {
        if (a[i] - del == mina) {
            inds.push_back(i);
        }
    }
    inds.push_back(r);

    /*cout << l << " - " << r << ": ";
    for (int i = 0; i < inds.size(); ++i) {
        cout << "(" << inds[i] << ")";
    }
    cout << "\n";*/

    ll ans = mina - (inds.size() - 2LL);
    for (int i = 0; i < inds.size() - 1; ++i) {
        ll ca = getm(mina + del, inds[i] + 1, inds[i + 1], a);
        if (ca < 0LL) {
            ans += ca;
        }
    }

    //cout << l << " - " << r << ": " << ans << "\n";
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = n;
    ans += min(0LL, getm(0, 0, n, a));

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}