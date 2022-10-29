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
    int n;cin>>n;
    int a[n];rep(i,0,n-1)cin>>a[i];
    ll sum=0;rep(i,0,n-1)sum+=a[i];
    if(sum<2*(n-1)){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<i_i> ans;
    vector<int> sin;
    vector<int> non;
    rep(i,0,n-1){
        if(a[i]==1){
            sin.pb(i);
            a[i]--;
        }
        else non.pb(i);
    }
    int di=non.size();
    
    if(sin.size()>=2)di+=2;
    else di+=sin.size();
    
    int k=non.size();
    rep(i,0,k-2){
        ans.pb(i_i(non[i],non[i+1]));
        a[non[i]]--;
        a[non[i+1]]--;
    }
    k=sin.size();
    if(k>=1){
        int last=n-1;while(a[last]==0)last--;
        ans.pb(i_i(sin[0],last));
        a[last]--;
    }
    
    int pos=0;
    rep(i,1,k-1){
        while(a[pos]==0)pos++;
        
        ans.pb(i_i(pos,sin[i]));
        a[pos]--;
    }
    cout<<"YES "<<di-1<<endl;
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first+1<<" "<<x.second+1<<endl;
    }
    return 0;
}