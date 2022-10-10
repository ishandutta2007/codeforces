    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    vector<pair<ll, ll>> fac;
     
    int main() {
        ll n, b;
        cin >> n >> b;
        for(ll d = 2; d * d <= b; d++) {
            if(b % d)
                continue;
            ll po = 0;
            while(b % d == 0) {
                b /= d;
                po++;
            }
            fac.emplace_back(d, po);
        }
        if(b > 1)
            fac.emplace_back(b, 1);
        ll ans = 1e18;
        for(auto pr : fac) {
            ll p = pr.first;
            ll m = n;
            ll vp = n;
            while(m > 0) {
                vp -= (m % p);
                m /= p;
            }
            vp /= (p - 1);
            ans = min(ans, vp/pr.second);
        }
        cout << ans << endl;
    }