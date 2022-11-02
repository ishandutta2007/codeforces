#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);

ll arr[1010101];
ll ans[1010][1010];
ll mp[1010][1010];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
vector<pii> v[505][505];
string s;
ll chk=0;

void dfs(ll i,ll j,ll val){
    ans[i][j]=val;
    for(auto k:v[i][j]){
        if(ans[k.ff][k.ss]==ans[i][j]) chk=1;
        if(ans[k.ff][k.ss]) continue;
        dfs(k.ff,k.ss,5-val);
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t,T;
    ll i,j,k,l,m,n;
    ll cnt=0,val;
    ll a=0,b=0,c=0,d=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>s;
        for(j=1;j<=m;j++){
            if(s[j-1]=='.') mp[i][j]=1;
            else mp[i][j]=2;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
           // cout<<i<<' '<<j<<'\n';
            cnt=0;
            vector<pii> p;
            if(mp[i][j]==1) continue;
            for(k=0;k<4;k++){
                ll x=i+dx[k];
                ll y=j+dy[k];
                if(mp[x][y]==1)
                    p.pb({x,y});
            }
            //cout<<p.size()<<'\n';
            if(p.size()%2)
                chk=1;
            ans[i][j]=p.size()*5/2;
            if(ans[i][j]==0) ans[i][j]=100;
            //cout<<i<<' '<<j<<' '<<ans[i][j]<<'\n';
            if(p.size()){
                for(k=0;k<p.size();k++){
                    //cout<<i<<j<<k<<'\n';
                    auto q1=p[k];
                    auto q2=p[k==p.size()-1 ? 0 :k+1];
                    //cout<<q1.ff<<' '<<q1.ss<<' '<<q2.ff<<' '<<q2.ss<<'\n';
                    v[q1.ff][q1.ss].pb(q2);
                    v[q2.ff][q2.ss].pb(q1);
                }
            }
        }
    }
    if(chk){
        cout<<"NO";
        return 0;   
    }

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(ans[i][j]==0){
                dfs(i,j,4);
            }
        }

    if(chk){
        cout<<"NO";
        return 0;
    }

    cout<<"YES"<<'\n';
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout<<ans[i][j]%100<<' ';
        cout<<'\n';
    }
}