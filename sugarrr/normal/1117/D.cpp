
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-9;
////////////////////////////////////////
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat a,mat b){/*ab*/
    mat c(a.size(),vec(b[0].size()));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                c[i][j]=mod(c[i][j]+mod(a[i][k]*b[k][j]));
            }
        }
    }
    return c;
}

mat pow(mat a,ll n){/*an*/
    mat b(a.size(),vec(a.size()));
    for(int i=0;i<a.size();i++){
        b[i][i]=1;
    }
    while(n>0){
        if(n&1)b=mul(b,a);
        a=mul(a,a);
        n>>=1;
    }
    return b;
}
//////////////////////////////////////////

int main(){
    ll n,m;cin>>n>>m;
    if(n<m){
        cout<<1<<endl;
        return 0;
    }
    mat a(m,vec(m));
    a[0][0]=1;a[0][m-1]=1;
    rep(i,1,m-1)a[i][i-1]=1;
    mat b=pow(a,n-m);
    /*rep(i,0,m-1){
        rep(j,0,m-1){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }*/
    mat c(m,vec(1));
    rep(i,1,m-1)c[i][0]=1;c[0][0]=2;
    mat d=mul(b,c);
    cout<<d[0][0]<<endl;
    
    
    return 0;
}