#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500009],s[500009],p[500009],m[500009];
main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= (n+1)/2; i++){
        cin >> a[i];
    }
    ll x;
    cin >> x;
    for(ll i = (n+1)/2+1; i <= n; i++){
        a[i] = x;
    }
    for(ll i =1; i <= n; i++){
        s[i] = s[i-1] + a[i];
        p[i] = p[i-1] + x - a[i];
        m[i] = min(m[i-1], p[i]);
    }
    for(ll k = (n+1)/2; k <= n; k++){
        if(s[k] <= 0) continue;
        if(s[k] + m[n - k] <= 0) continue;
        cout<<k<<endl;
        return  0;
    }
    cout<<-1<<endl;
    return 0;


}
/*


*/