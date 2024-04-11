#include <bits/stdc++.h>
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


int main(){
    ll n;cin>>n;
    string ss;cin>>ss;
    ll s[n];
    rep(i,0,n-1){
        if(ss[i]=='R')s[i]=0;
        else if(ss[i]=='B')s[i]=1;
        else s[i]=2;
    }
    ll t[6][3];
    ll q[3]={0,1,2};
    ll z=0;
    do{
        rep(j,0,2)t[z][j]=q[j];
        z++;
    }while(next_permutation(q,q+3));
    ll u[6][n];
    rep(i,0,5){
        if(n>=3){
            rep(j,0,2)u[i][j]=t[i][j];
            rep(j,3,n-1)u[i][j]=u[i][j-3];
        }else{
            rep(j,0,n-1)u[i][j]=t[i][j];
        }
    }
    ll mi=inf,mipos=-1;
    rep(i,0,5){
        ll c=0;
        rep(j,0,n-1){
            if(s[j]!=u[i][j])c++;
        }
        if(c<mi){
            mi=c;
            mipos=i;
        }
    }
    //cout<<mipos<<endl;
    cout<<mi<<endl;
    string ans;
    rep(j,0,n-1){
        if(u[mipos][j]==0)ans+='R';
        else if(u[mipos][j]==1)ans+='B';
        else ans+='G';
    }
    cout<<ans<<endl;
    
    return 0;
}