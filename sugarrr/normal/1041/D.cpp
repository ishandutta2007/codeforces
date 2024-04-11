#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    
    ll n,h;cin>>n>>h;
    ll x[n][2];rep(i,0,n-1)rep(j,0,1)cin>>x[i][j];
    
    ll a[n];rep(i,0,n-1)a[i]=x[i][1]-x[i][0];
    rep(i,1,n-1)a[i]=a[i]+a[i-1];
    ll b[n-1];rep(i,1,n-1)b[i-1]=x[i][0]-x[i-1][1];
    //rep(i,0,n-1)cout<<a[i]<<" ";cout<<endl;
   // rep(i,0,n-2)cout<<b[i]<<" ";
    
    ll ans=0;
    ll s=0,t=0;
    ll sum=0;
    while(s<=n-1&&t<=n-1){
        while(t<=n-2&&sum+b[t]<h){
            sum+=b[t];
            t++;
        }
        ll cal;
        if(s==0)cal=a[t];
        else cal=a[t]-a[s-1];
        
        //cout<<s<<" "<<cal<<endl;
        
        cal+=h;
        ans=max(cal,ans);
        
        sum-=b[s];
        s++;
        
    }
    cout<<ans<<endl;
    return 0;
}