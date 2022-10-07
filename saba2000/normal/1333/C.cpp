#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],s[200009];
map<ll,ll> M;
main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    ll m = -1, ans = 0;
    M[0] = 0;
    for(int i = 1; i <= n; i++){
        if(M.find(s[i]) != M.end()){
            m = max(m, M[s[i]]);
        }
        ans += i - m - 1;
        M[s[i]] = i;
    }
    cout << ans << endl;

}