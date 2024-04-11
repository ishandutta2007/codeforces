#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> divs;
    for(ll d = 1; d*d <= n; d++) {
        if(n % d == 0) {
            divs.push_back(d);
            divs.push_back(n/d);
        }
    }
    set<ll> ans;
    for(auto a : divs) {
        ll k = n/a;
        ans.insert(a*k*(k - 1)/2ll + k);
    }
    for(auto a : ans)
        cout << a << " ";
    cout << endl;
}