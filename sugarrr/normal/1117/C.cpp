
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

int main(){
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    ll x=x2-x1,y=y2-y1;
    ll n;cin>>n;
    string s;cin>>s;
    /*if(x<0){
        rep(i,0,n-1){
            if(s[i]=='L')s[i]='R';
            else if(s[i]=='R')s[i]='L';
        }
        x*=-1;
    }
    if(y<0){
        rep(i,0,n-1){
            if(s[i]=='U')s[i]='D';
            else if(s[i]=='D')s[i]='U';
        }
        y*=-1;
    }*/
    ll dx[n+1],dy[n+1];
    dx[0]=0;dy[0]=0;
    rep(i,0,n-1){
        dx[i+1]=dx[i];dy[i+1]=dy[i];
        if(s[i]=='U')dy[i+1]++;
        else if(s[i]=='D')dy[i+1]--;
        else if(s[i]=='L')dx[i+1]--;
        else dx[i+1]++;
    }
    ll l=0,r=(ll)1E16+10;
    while(r>l){
        ll m=(l+r)/2;
        ll p=m/n;
        ll q=m-p*n;
        ll nx=dx[n]*p+dx[q];
        ll ny=dy[n]*p+dy[q];
        if(abs(nx-x)+abs(ny-y)<=m){
            r=m;
        }else{
            l=m+1;
        }
    }
    if(l>=(ll)1E16){
        cout<<-1<<endl;return 0;
    }
    cout<<l<<endl;
    
    return 0;
}