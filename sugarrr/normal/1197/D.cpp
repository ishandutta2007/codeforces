#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

ll m,k;
ll cal(vector<ll>v){
    ll ret=0;
    ll n=v.size();
    ll ds=(n+m-1)/m;
    ll ap[ds+1];
    ll bp[ds+1];memset(bp,0,sizeof(bp));
    ap[0]=0;
    rep(i,1,ds)ap[i]=-k;
    rep(i,1,ds){
        ll sum=0;
        for(ll j=(i-1)*m;j<=i*m-1&&j<=n-1;j++){
            sum+=v[j];
            Max(bp[i],sum-k);
            ap[i]+=v[j];
        }
    }
    
   // rep(i,0,ds)cout<<ap[i]<<" ";cout<<endl;
   // rep(i,0,ds)cout<<bp[i]<<" ";cout<<endl;
    
    ll pos=1;
    while(pos<=ds){
        ll npos=pos;
        ll presuma=0;
        while(npos<=ds){
            presuma+=ap[npos];
            if(presuma>=0){
                npos++;
            }else{
                break;
            }
        }
        ll suma=0;
        rep(i,pos-1,npos){
            if(i>ds)break;
            if(i!=pos-1)suma+=ap[i];
            ll sum=suma;
            if(i==npos){
                
            }else{
                if(i+1<=ds)sum+=bp[i+1];
            }
            Max(ret,sum);
        }
        pos=npos+1;
    }
    //cout<<ret<<endl;
    return ret;
}
int main(){
    
    ll n;cin>>n>>m>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll ans=0;
    rep(i,0,m-1){
        vector<ll>v;
        rep(j,i,n-1){
            v.pb(a[j]);
        }
        Max(ans,cal(v));
    }
    cout<<ans<<endl;
    return 0;
}