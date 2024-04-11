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

struct num{
    ll i,j;
    ll val;
};
bool comp(num a,num b){
    return a.val>b.val;
}

bool ansp(){
    ll n,m;cin>>n>>m;
    ll a[n][m];
    vector<num>v;
    rep(i,0,n-1)rep(j,0,m-1){
        cin>>a[i][j];
        num k;k.i=i;k.j=j;k.val=a[i][j];
        v.pb(k);
    }
    sort(v.begin(),v.end(),comp);
    if(n<=3){
        ll ans=0;rep(i,0,n-1)ans+=v[i].val;
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        ll ans=0;for(auto x:v)ans+=x.val;
        cout<<ans<<endl;
        return 0;
    }
    ll ans=0;
    rep(x,0,(1<<7)-1){
        ll cou=0;
        ll sum=0;
        rep(y,0,6){
            if((x>>y)&1){
                cou++;
                sum+=a[v[y].i][v[y].j];
            }
        }
        if(cou!=4)continue;
        bool b[n][m];memset(b,false,sizeof(b));
        ll c[m];memset(c,0,sizeof(c));
        rep(y,0,6){
            if((x>>y)&1){
                b[v[y].i][v[y].j]=true;
                c[v[y].j]++;
            }
        }
        bool nexf=false;
        rep(j,0,m-1){
            if(c[j]==1||c[j]==3){
                nexf=true;
                Max(ans,sum);
            }
        }
        if(nexf)continue;
        ll t1=-1,t2=-1;
        rep(j,0,m-1){
            ll res=0;
            
            if(c[j]==2){
                if(b[0][j]&&b[2][j])res=1;
                if(b[1][j]&&b[3][j])res=1;
            }else{
                continue;
            }
            if(t1==-1)t1=res;
            else t2=res;
        }
        if(t1+t2!=1)Max(ans,sum);
    }
    cout<<ans<<endl;
    
    
    return 0;
}

int main(){fastio
    ll q;cin>>q;
    while(q--){
        ansp();
    }
    
    return 0;
}



/*
 
 10
 
 4 4
 10 10 0 0
 10 0 0 0
 0 10 0 0
 0 0 0 0
 
 */