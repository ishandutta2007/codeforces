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
#define N 100005
UF<N>uf;//Nconst int
//uf(a,b);//ab
//uf.same(a,b);//ab
//uf[i];//ireturn

struct edge{
    ll a,b;
    ll num;
};
bool comp(edge x,edge y){
    return x.num<y.num;
}
int main(){fastio
    ll n,k;cin>>n>>k;
    edge e[k];
    rep(i,0,k-1){
        cin>>e[i].a>>e[i].b;
        e[i].a--;e[i].b--;
        uf(e[i].a,e[i].b);
        
    }
    rep(i,0,k-1){
        e[i].num=uf[e[i].a];
    }
    sort(e,e+k,comp);
    //rep(i,0,k-1)cout<<e[i].num<<" "<<e[i].a<<" "<<e[i].b<<endl;
    set<ll>s;
    ll cou=0;
    ll ans=0;
    rep(i,0,k-1){
        s.insert(e[i].a);s.insert(e[i].b);
        cou++;
        if(i==k-1||e[i].num!=e[i+1].num){
            ans+=s.size()-1;
            s.clear();cou=0;
        }
    }
    cout<<k-ans<<endl;
    
    return 0;
}