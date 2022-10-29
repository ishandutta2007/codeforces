
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
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
// long double EPS=1E-8;
////////////////////////////////////////

ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};



int main() {
    ll n,m,p;cin>>n>>m>>p;
    ll f[p];rep(i,0,p-1)cin>>f[i];
    string s[n];rep(i,0,n-1)cin>>s[i];
    l_l a[n][m];rep(i,0,n-1)rep(j,0,m-1)a[i][j]=l_l(inf,inf);
    queue<l_l>q[p];
    rep(i,0,n-1)rep(j,0,m-1){
        if('1'<=s[i][j]&&s[i][j]<='9'){
            q[s[i][j]-'1'].push(l_l(i,j));
            a[i][j]=l_l(0,s[i][j]-'1');
        }
    }
    for(ll turn=1;;turn++){
        bool flag=true;
        rep(i,0,p-1){
            while(!q[i].empty()){
                l_l now=q[i].front();
                ll x=now.first,y=now.second;
                if(a[x][y].first>=turn*f[i]){
                    break;
                }
                q[i].pop();
                rep(j,0,3){
                    ll nx=x+dx[j],ny=y+dy[j];
                    if(0<=nx&&nx<=n-1&&0<=ny&&ny<=m-1&&s[nx][ny]=='.'&&a[nx][ny].first==inf){
                        a[nx][ny]=l_l(a[x][y].first+1,i);
                        q[i].push(l_l(nx,ny));
                        flag=false;
                    }
                }
            }
        }
        if(flag)break;
    }
    /*
        rep(i,0,n-1){
            rep(j,0,m-1){
                cout<<a[i][j];
            }cout<<endl;
        }cout<<endl;
    */
    ll ans[p];memset(ans,0,sizeof(ans));
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(a[i][j].first==inf)continue;
            ans[a[i][j].second]++;
        }
    }
    rep(i,0,p-1)cout<<ans[i]<<" ";
    
    
    return 0;
}