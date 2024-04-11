#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
 
struct poi{
    ll val,xx,yy;
};
 
vector<ll> x;
ll arr[2020][2020];
ll n,m;
ll mod=998244353;
string s;
 
ll fld[4040][4040];
ll ans[4040][4040];
vector<poi> v;
 
bool sf(poi a,poi b){
    return a.val>b.val;
}
 
 
ll mi,mj;
ll rv,lv,uv,dv;
 
ll gdis(ll x,ll y){
    return max(abs(x-mi),abs(y-mj));
}
 
ll chk(ll x,ll y){
    if(gdis(x-rv,y)>m) return 0;
    if(gdis(x+lv,y)>m) return 0;
    if(gdis(x,y-dv)>m) return 0;
    if(gdis(x,y+uv)>m) return 0;
 
    return 1;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,l;
    cin>>n>>m;
    
 
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
            ll x=i+j-1;
            ll y=n+j-i;
            fld[x][y]=arr[i][j];
            if(arr[i][j]==n*n){
                mi=x;
                mj=y;
            }
            poi p={arr[i][j],x,y};
            v.pb(p);
        }
 
    sort(v.begin(), v.end(),sf);
 
    for(auto k:v){
       //cout<<mi<<' '<<mj<<' '<<k.val<<' '<<k.xx<<' '<<k.yy<<'\n';
       //cout<<rv<<' '<<lv<<' '<<dv<<' '<<uv<<'\n';
        if(gdis(k.xx,k.yy)<=m){
            if(chk(k.xx,k.yy)){
                if(k.xx>mi){
                    rv=max(rv,k.xx-mi);
                }
                if(k.xx<mi){
                    lv=max(lv,mi-k.xx);
                }
                if(k.yy>mj){
                    dv=max(dv,k.yy-mj);
                }
                if(k.yy<mj){
                    uv=max(uv,mj-k.yy);
                }
                ans[k.xx][k.yy]=1;
            }
        }
    }
 
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            ll x=i+j-1;
            ll y=n+j-i;
            if(ans[x][y]) cout<<"M";
            else cout<<"G";
        }
        cout<<'\n';
    }
 
 
}