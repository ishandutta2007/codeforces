#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define ii pair<ll,ll>
#define ld long double
#define e '\n'
#define sp ' '
#define pb push_back
#define po pop_back()
#define in insert
#define mk make_pair
#define er erase
#define R return
#define se second
#define co continue
#define fi first
#define fr front()
#define ba back()
#define si size()
#define em empty()
#define be begin()
#define ee end()
#define mod 1000000007
#define eb 0.000000001

ll l,r,ans,f,s,bo,a,b;
vector<ll> v;
ll fpm(ll x,ll y){
    if(y==0) R 1;
    if(y==1) R x;
    ll res=fpm(x,y/2)%mod;
    if(y%2==0) R (res*res)%mod;
    else R (fpm(x,y-1)%mod*x%mod)%mod;
}
ll inc(ll a,ll b,ll i){
    f=a-v[i-1];
    for(int j=i-3;j>=0;j-=2) f+=v[j];
    s=b-v[i-1];
    for(int j=i-3;j>=0;j-=2) s+=v[j];
    if(i%2) {s*=2; s++; f*=2; f++;}
    else {s++; s*=2; f++; f*=2;}
    R (((((b-a+1)%mod)*(((f+s)/2)%mod))%mod))%mod;
}

int main(){
    cin>>l>>r;
    for(int i=0;i<=60;i++) v.pb(pow(2,i));
    for(int i=0;i<=60;i++){
        if(l<v[i]&&!bo){
            if(r<v[i]) R cout<<inc(l,r,i)<<e,0;
            ans+=inc(l,v[i]-1,i);
            ans%=mod;
            bo=i+1;
        }
        if(r<v[i]){
            ans+=inc(v[i-1],r,i);
            ans%=mod;
            R cout<<ans<<e,0;
        }
        else if(bo&&bo!=i+1){
            ans+=inc(v[i-1],v[i]-1,i);
            ans%=mod;
        }
    }
    R 0;
}