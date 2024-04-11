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
////////////////////////////


struct point{
    ll x,y,z;
    ll num;
};
bool comp(point a,point b){
    if(a.x<b.x)return true;
    if(a.x>b.x)return false;
    if(a.y<b.y)return true;
    if(a.y>b.y)return false;
    return a.z<b.z;
}
vector<l_l>ans;

int main(){fastio
    ll n;cin>>n;
    point p[n];
    rep(i,0,n-1){
        p[i].num=i+1;
        cin>>p[i].x>>p[i].y>>p[i].z;
    }
    sort(p,p+n,comp);
    ll pos=0;
    vector<point>v;
    while(pos<=n-2){
        if(p[pos].x==p[pos+1].x&&p[pos].y==p[pos+1].y){
            ans.pb(l_l(p[pos].num,p[pos+1].num));
            pos+=2;
        }else{
            v.pb(p[pos]);
            pos++;
        }
    }
    if(pos==n-1)v.pb(p[pos]);
    vector<point>las;
    pos=0;
    ll vs=v.size();
    while(pos<=vs-2){
        if(v[pos].x==v[pos+1].x){
            ans.pb(l_l(v[pos].num,v[pos+1].num));
            pos+=2;
        }else{
            las.pb(v[pos]);
            pos++;
        }
    }
    if(pos==vs-1)las.pb(v[pos]);
    ll lass=las.size();
    for(ll i=0;i<=lass-2;i+=2){
        ans.pb(l_l(las[i].num,las[i+1].num));
    }
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    return 0;
}