
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
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
long double EPS=1E-8;
////////////////////////////////////////

ll que(ll pos){
    cout<<"? "<<pos<<endl;
    fflush(stdout);
    ll k;cin>>k;
    return k;
}
bool up(ll x){
    cout<<"> "<<x<<endl;
    fflush(stdout);
    ll k;cin>>k;
    return k;
}
void fin(ll x,ll d){
    cout<<"! "<<x<<" "<<d<<endl;
    fflush(stdout);
    ll r;cin>>r;
}
ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    else return gcd(b%a,a);
}
unsigned int rnd(){
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

int main(){
    ll n;cin>>n;
    ll ok=0,ng=(ll)1E9+1;
    while(abs(ok-ng)>1){
        ll m=(ok+ng)/2;
        bool flag=up(m);
        if(flag){
            ok=m;
        }else{
            ng=m;
        }
    }
    ll ma=ok+1;
    //cout<<ma<<endl;
    ll g=0;
    vector<ll>p;
    if(n<=20){
        rep(i,1,n){
            ll val=que(i);
            p.pb(val);
        }
    }else{
        rep(qqq,1,25){
            ll pos=n-rnd()%n;
            if(1<=pos&&pos<=n){
                ll val=que(pos);
                p.pb(val);
            }
        }
        p.pb(ma);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    ll ps=p.size();
    rep(i,0,ps-1){
        rep(j,i+1,ps-1){
            g=gcd(g,abs(p[j]-p[i]));
        }
    }
    ll minim=ma-(n-1)*g;
    
    fin(minim,g);
    return 0;
}