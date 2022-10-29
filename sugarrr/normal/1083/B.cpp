
 #include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////


int main(){
    
    ll n,k;cin>>n>>k;
    string ss,tt;cin>>ss>>tt;
    if(k==1){
        cout<<n<<endl;
        return 0;
    }
    if(ss==tt){
        cout<<n<<endl;
        return 0;
    }
    k-=2;
    
    int same=0;
    while(1){
        if(ss[same]==tt[same]){
            same++;
        }else{
            break;
        }
    }
    string s=ss.substr(same,n-same);
    string t=tt.substr(same,n-same);
    n=n-same;
    ll count[2][n+1];memset(count,0,sizeof(count));
    
    rep(i,1,n-1){
        ll d=n-i;
        if(s[i]=='a'){
            if(d>=1)count[0][d]++;
            if(d-1>=1)count[1][d-1]++;
        }
        if(t[i]=='b'){
            if(d>=1)count[0][d]++;
            if(d-1>=1)count[1][d-1]++;
        }
    }
   /* rep(i,0,1){
        rep(j,0,n){
            cout<<count[i][j]<<" ";
        }cout<<endl;
    }*/
    
    ll ans=same;
    for(ll i=n;i>=1;i--){
        if(count[0][i]<=k){
            ans+=count[0][i]*i;
            k-=count[0][i];
        }else{
            ans+=k*i;
            k-=k;
        }
        if(count[1][i]<=k){
            ans+=count[1][i]*i;
            k-=count[1][i];
            count[1][i-1]+=count[1][i]*2;
        }else{
            ans+=k*i;
            k-=k;
        }
    }
    
    
    cout<<ans+2*n<<endl;
    
    return 0;
}