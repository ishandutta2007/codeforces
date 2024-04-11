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


//[1,n]
#define max_n 200020//
ll bit[max_n+1],n;
ll sum(ll i){//a[1]~a[i]
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x){//a[i]x
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
   
    ll t;cin>>n>>t;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    ll su[n+1];su[0]=0;
    rep(i,1,n)su[i]=su[i-1]+a[i];
    
    ll all[n+1];rep(i,1,n)all[i]=su[i];
    sort(all+1,all+n+1);
    /*rep(i,1,n){
        cout<<all[i]<<" ";
    }cout<<endl;*/
    
    ll ans=0;
    rep(i,0,n-1){
        ll cal=t+su[i];
        ll posx=lower_bound(all+1,all+n+1,cal)-(all);
        ll y=sum(posx-1);
        ans+=(posx-1)-y;
        
        ll posz=lower_bound(all+1,all+n+1,su[i+1])-(all);
        add(posz,1);
     //   cout<<i<<" "<<ans<<endl;
        
    }
    cout<<ans<<endl;
    
    return 0;
}