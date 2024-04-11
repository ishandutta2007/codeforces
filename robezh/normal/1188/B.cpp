#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod;

int n, k;


int main(){
    cin >> n >> mod >> k;

    map<ll, int> mp;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        ll x = 1LL * a * a % mod * a % mod * a - 1LL * a * k;
        mp[(x % mod + mod) % mod]++;
    }
    ll res = 0;
    for(auto p : mp) res += 1LL * p.second * (p.second - 1) / 2;
    cout << res << endl;

}