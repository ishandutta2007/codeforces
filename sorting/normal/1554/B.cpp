#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for(ll &x: a)
            cin >> x;

        int start = max(n - k - 3, 0ll);
        ll ans = LLONG_MIN;
        for(int i = start; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                ans = max(ans, (ll)(i + 1) * (j + 1) - k * (a[i] | a[j]));

        cout << ans << "\n";
    }
}