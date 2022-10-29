#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
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
template<int um> class UF {
public:
    vector<int> par,rank;
    UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
    int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
    int operator()(int x,int y) {
        if((x=operator[](x))==(y=operator[](y))) return x;
        if(rank[x]<rank[y]) return par[x]=y;//rankxy
        rank[x]+=rank[x]==rank[y]; return par[y]=x;//rankxyrank++
    }
    bool same(int x,int y){return operator[](x)==operator[](y);}
};
#define N 200005
UF<N>uf;//Nconst int
//uf(a,b);//ab
//uf.same(a,b);//ab
//uf[i];//ireturn

int main(){fastio
    ll n,deb;cin>>n>>deb;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    vector<ll>v;rep(i,0,n-1)v.pb(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    rep(i,0,n-1){
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    }
    
    //rep(i,0,n-1)cout<<a[i]<<" ";cout<<endl;
    ll vs=v.size();//cout<<vs<<endl;
    ll l[vs],r[vs];
    rep(i,0,vs-1){
        l[i]=inf;
        r[i]=-inf;
    }
    rep(i,0,n-1){
        Min(l[a[i]],i);
        Max(r[a[i]],i);
    }
    //rep(i,0,vs-1)cout<<i<<":"<<l[i]<<" "<<r[i]<<endl;
    ll cou[n];memset(cou,0,sizeof(cou));
    rep(i,0,n-1){
        cou[a[i]]++;
    }
    ll ma=-100;
    rep(i,0,n-1){
        Max(ma,r[a[i]]);
        if(ma==i){
            
        }else{
            if(i!=n-1)uf(i,i+1);
        }
    }
    /*rep(i,0,n-1){
        cout<<uf[i]<<" ";
    }cout<<endl;
    */
    set<ll>s;
    ll ans=0;
    ll pos=0;
    while(pos<=n-1){
        s.insert(a[pos]);
        while(pos+1<=n-1&&uf[pos]==uf[pos+1]){
            s.insert(a[pos+1]);
            pos++;
        }
        vector<ll>res;
        for(auto x:s){
            res.pb(cou[x]);
        }
        sort(res.begin(),res.end());
        ll ress=res.size();
        rep(i,0,ress-2)ans+=res[i];
        s.clear();
        pos++;
    }
    cout<<ans<<endl;
    return 0;
}