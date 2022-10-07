#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ss[1000009];
ll sx[1000009];
ll sy[1000009];
ll sm[1000009];
ll M[1000009];
ll inv[1000009];
ll mod = 998244353;
main(){
    
    int n, m;
    cin >> n>> m;
    vector<pair<ll,pair<ll,ll> > > v;
    v.push_back({0,{0,0}});
    
    for(int i = 1; i <= n; i++){
        for(int j  = 1; j<= m; j++){
            int a;
            cin >> a;
            v.push_back({a,{i,j}});
        }
    }
    int r,c;
    cin>>r>>c;
    sort(v.begin(),v.end());
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i <= n*m; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    int j = 0;
    for(int i = 1; i < v.size(); i++){
        
        while(v[j + 1].first < v[i].first) j++;
        ll x = v[i].second.first,
            y = v[i].second.second;
        if(j == 0) M[i] = 0; else{
        M[i] = ((sm[j] + x*x%mod*j%mod + y*y%mod*j%mod+ ss[j] - 2 * x * sx[j] - 
        2 * y * sy[j]) % mod + mod)%mod;
        M[i] = (M[i] * inv[j]) % mod;
        }
        
        if(x == r && y == c) {
            cout<<M[i]<<endl;
            return 0;
        }
        ss[i] = (ss[i - 1] + x
        * x +y * y)%mod;
        sx[i] = (sx[i - 1] + x)%mod;
        sy[i] = (sy[i - 1] + y)%mod;
        sm[i] = (sm[i - 1] + M[i])%mod;
    }
}