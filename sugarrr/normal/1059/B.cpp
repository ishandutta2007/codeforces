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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
const double EPS=1E-8;
////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    int n,m;cin>>n>>m;
    string q[n];rep(i,0,n-1)cin>>q[i];
    int s[n][m];
    rep(i,0,n-1)rep(j,0,m-1){
        if(q[i][j]=='.')s[i][j]=0;
        else s[i][j]=1;
    }
    int t[n][m];memset(t,0,sizeof(t));
    rep(i,1,n-2)rep(j,1,m-2){
        bool flag=true;
        rep(k,-1,1)rep(l,-1,1){
            if(k!=0||l!=0){
                if(s[i+k][j+l]==0){flag=false;break;}
            }
        }
        if(flag){
            rep(k,-1,1)rep(l,-1,1){
                if(k!=0||l!=0){
                    t[i+k][j+l]=1;
                }
            }
        }
    }
    
    rep(i,0,n-1)rep(j,0,m-1){
        if(s[i][j]!=t[i][j]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
    return 0;
}