#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009];
ll f[100009];
ll n;
void upd(ll x){
    while(x <= n){
        f[x]++;
        x += (x&-x);
    }
}
ll cnt(ll x){
    ll ans = 0;
    while(x){
        ans += f[x];
        x -= x&-x;
    }
    return ans;
}
main(){
    string s;
    cin >> s;
     n = s.size();
    for(ll i =0 ; i < s.size(); i++)
        if(s[i] == '?') a[i+1] = -1;
        else a[i+1] = s[i] - '0';
    ll x, y;
    cin >> x >> y;
    if(x > y){
        swap(x, y);
        for(ll i = 1; i <= n; i++)
            if(a[i] >= 0) a[i] ^= 1;
    }
    vector<ll> v;
    ll A = 0, B = 0, o = 0, z =0;
    for(ll i = 1; i <= n; i++){
        if(a[i] == -1) a[i] = 0, v.push_back(i);
        if(a[i] == 0) z++;
        else{
            upd(i);
            o++;
            A += z;
        }
    }
    B = o*z-A;
    ll ans = x*A + y*B;
    reverse(v.begin(), v.end());
    for(ll i : v){
        ll O = cnt(i);
        B -= O;
        A -= o - O;
        upd(i);
        o++; z--;
        ll Z = i - cnt(i);
        A += Z;
        B += z - Z;
        ans = min(ans, x*A + y*B);
    }
    cout<<ans<<endl;


}
//1 2
//2 3
//3 1