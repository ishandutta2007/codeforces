    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    int main() {
        int n;
        ll m, k;
        cin >> n >> m >> k;
        vector<ll> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        ll mx = *max_element(v.begin(), v.end());
        ll omx = 0;
        bool smx = false;
        for(int i = 0; i < n; i++) {
            if(!smx && v[i] == mx)
                smx = true;
            else
                omx = max(omx, v[i]);
        }
        ll s = k*mx + omx;
        ll ans = m/(k + 1) * s;
        m %= k + 1;
        ans += m*mx;
        cout << ans << endl;
     
    }