

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
//ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=*pos+val;}
//const long double EPS=1E-8;
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll a,b;cin>>a>>b;
    ll c=a+b;
    ll m=1;
    while(m*(m+1)/2<=c)m++;
    m--;
    bool used[m+1];memset(used,false,sizeof(used));
    vector<int>va,vb;
    for(int i=m;i>=1;i--){
        if(a>=i){
            a-=i;
            va.pb(i);
            used[i]=true;
        }
        if(a==0)break;
    }
    for(int i=1;i<=m;i++){
        if(!used[i])vb.pb(i);
    }
    ll as=va.size(),bs=vb.size();
    cout<<as<<endl;
    rep(i,0,as-1)cout<<va[i]<<" ";
    cout<<endl;
    cout<<bs<<endl;
    rep(i,0,bs-1)cout<<vb[i]<<" ";
    cout<<endl;
    
    
    return 0;
}
//ios::sync_with_stdio(false);cin.tie(0);