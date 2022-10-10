#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for(auto &x : v) {
        cin >> x;
        sum += x;
    }
    sort(v.rbegin(), v.rend());
    ll quo = sum / n, rem = sum % n, ans = 0;
    for(int i = 0; i < n; i++) {
        ll tar = quo + (i < rem);
        if(v[i] > tar)
            ans += v[i] - tar;
    }
    cout << ans << '\n';
}