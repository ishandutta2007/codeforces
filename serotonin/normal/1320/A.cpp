#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

map <ll,ll> mp;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        ll x;
        scanf("%lld", &x);
        mp[x-i]+=x;
    }

    ll ans=0;
    for(auto it : mp) ans = max(ans, it.second);

    cout << ans;
}