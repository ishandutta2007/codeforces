#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    ll n, k, m;
    cin >> n >> k >> m;
    ll sum = 0LL;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    
    ld ans = 0;
    for (int i = 0; i < min(n, m + 1); ++i) {
        ld cur = sum;
        cur += min(k * (n - i), m - i);
        cur /= (n - i);
        ans = max(ans, cur);
        sum -= a[i];
    }
    
    cout << setprecision(20) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}