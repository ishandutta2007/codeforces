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
    
    ll n,m;cin>>n>>m;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    ll sum=0;rep(i,0,n-1)sum+=a[i];
    ll ans1,ans2=a[n-1]+m;
    ans1=((m+sum)+n-1)/n;
    ans1=max(ans1,a[n-1]);
    cout<<ans1<<" "<<ans2<<endl;
    
    
    
    return 0;
}