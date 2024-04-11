

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////
const int DAT_SIZE=(1<<22)-1;//
//(0-indexed)
ll data[DAT_SIZE],datb[DAT_SIZE];
//[a,b)x k[l,r)
void add(ll a,ll b,ll x,ll k,ll l,ll r){
    if(a<=l&&r<=b){
        data[k]+=x;
    }else if(l<b&&a<r){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
//[a,b) k[l,r)
ll sum(ll a,ll b,ll k,ll l,ll r){
    if(b<=l||r<=a){
        return 0;
    }else if(a<=l&&r<=b){
        return data[k]*(r-l)+datb[k];
    }else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
/////////////////////////////////////////////////////////
//ex ax:add(a,a+1,x,0,0,n);


int main() {
    int n;cin>>n;
    ll v[n];rep(i,0,n-1)cin>>v[i];
    ll t[n];rep(i,0,n-1)cin>>t[i];
    ll sumt[n];
    sumt[0]=t[0];rep(i,1,n-1)sumt[i]=sumt[i-1]+t[i];
    ll c[n];memset(c,0,sizeof(c));
    ll ama[n];memset(ama,0,sizeof(ama));
    ll su=0;
    rep(i,0,n-1){
        
        ll k=lower_bound(sumt+i,sumt+n,v[i]+su)-sumt;
        add(i,k,1,0,0,n);
        if(k>0)ama[k]+=v[i]+su-sumt[k-1];
        else ama[k]+=v[i]+su;
        su+=t[i];
    }
    rep(i,0,n-1){
        c[i]=sum(i,i+1,0,0,n)*t[i];
    }
    rep(i,0,n-1){
        c[i]+=ama[i];
    }
    rep(i,0,n-1){
        cout<<c[i]<<" ";
    }
    return 0;
}