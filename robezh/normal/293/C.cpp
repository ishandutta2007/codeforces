#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> divs;

int main() {
    cin >> n;
//    double old =  (double)clock() / CLOCKS_PER_SEC;
    if(n % 3 != 0) return cout << 0 << endl, 0;
    n /= 3;
    ll res = 0;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(n / i != i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    int len = divs.size();
    for(auto it = divs.begin(); it != divs.end() && *it * *it * *it <= n; it++) {
        ll i = *it;
        if(n % i != 0) continue;
        for(auto it2 = lower_bound(divs.begin(), divs.end(), i); it2 != divs.end() && i * *it2 * *it2 <= n; it2++) {
            ll j = *it2;
            if(n / i % j != 0) continue;
            ll k = n / i / j;
            if(j > k || (i + j + k) % 2 == 1) continue;
            ll sum = (i + j + k) / 2;
            ll a = sum - k, b = sum - j, c = sum - i;
            if(a <= 0) continue;
            if(a == b && b == c) res++;
            else if(a == b || b == c) res += 3;
            else res += 6;
        }
    }
//    cout << (double)clock() / CLOCKS_PER_SEC - old << endl;
    cout << res << endl;
}