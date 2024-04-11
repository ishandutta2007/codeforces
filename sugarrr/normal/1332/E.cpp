//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////


ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}




typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat a,mat b){/*ab*/
    mat c(a.size(),vec(b[0].size()));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                c[i][j]=mod(c[i][j]+a[i][k]*b[k][j]);
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


int main(){fastio
    ll n,m,l,r;cin>>n>>m>>l>>r;
    if((n*m)%2==1){
        cout<<po(r-l+1,n*m);
        return 0;
    }
    ll E=(r-l+1)/2;
    ll O=E;
    if((r-l+1)%2==1){
        if(l%2==1)O++;
        else E++;
    }
    mat a(2,vec(2));
    a[0][0]=a[1][1]=mod(E);
    a[1][0]=a[0][1]=mod(O);
    a=pow(a,n*m);
    mat b(2,vec(1));
    b[0][0]=1;
    b[1][0]=0;
    b=mul(a,b);
    cout<<mod(b[0][0])<<endl;
    
    return 0;
}