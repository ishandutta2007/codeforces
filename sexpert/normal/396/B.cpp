#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(ll n) {
    for(ll d = 2; d * d <= n; d++) {
        if(n % d == 0)
            return false;
    }
    return true;
} 

void solve() {
    ll n;
    cin >> n;
    ll p, q;
    for(p = n; ;p--) {
        if(is_prime(p))
            break;
    }
    for(q = n + 1; ;q++) {
        if(is_prime(q))
            break;
    }
    ll num = (p*q - 2*q + 2*(n - p + 1)), den = 2*p*q;
    ll g = __gcd(num, den);
    cout << num/g << "/" << den/g << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}