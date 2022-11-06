#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);

        set <ll> ans;
        ans.insert(0);
        for(ll i=1; i*i<=n; i++) {
            ll d=n/i;
            ans.insert(d);
            ans.insert(i);
            if(d==i) break;
        }

        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
}