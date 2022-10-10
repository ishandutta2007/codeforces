#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    ll S = accumulate(v.begin(), v.end(), 0LL);
    ll num = 0, den = n;
    sort(v.begin(), v.end());
    ll times = n - 1;
    for(int i = n - 1; i >= 0; i--) {
        num += v[i] * times;
        times -= 2;
    }
    num *= 2;
    num += S;
    ll d = __gcd(num, den);
    num /= d;
    den /= d;
    cout << num << " " << den << '\n';
}