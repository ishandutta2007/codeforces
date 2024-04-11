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
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
ll mod=998244353;
//ll arr[1010101];
 
ll n,m;
string s;
//vector<pii> ans;
ll inf=1e18;
ll day;
int arr[1010101];
ll chk[1010101];
ll ans[1010101];
 
struct node{
    ll val,laz;
};
node tree[1010101];
 
ll upt(ll l,ll r,ll val,ll s,ll e,ll nod){
    if(tree[nod].laz!=0){
        tree[nod].val+=tree[nod].laz;
        if(s!=e){
            tree[nod*2].laz+=tree[nod].laz;
            tree[nod*2+1].laz+=tree[nod].laz;
        }
        tree[nod].laz=0;
    }
    if(r<s||e<l) return tree[nod].val;
    if(l<=s&&e<=r){
        if(s!=e){
            tree[nod*2].laz+=val;
            tree[nod*2+1].laz+=val;
        }
        tree[nod].val+=val;
        return tree[nod].val;
    }
    return tree[nod].val=min(upt(l,r,val,s,(s+e)/2,nod*2),
                            upt(l,r,val,(s+e)/2+1,e,nod*2+1));
}
 
ll sol(ll l,ll r,ll s,ll e,ll nod){
    if(tree[nod].laz!=0){
        tree[nod].val+=tree[nod].laz;
        if(s!=e){
            tree[nod*2].laz+=tree[nod].laz;
            tree[nod*2+1].laz+=tree[nod].laz;
        }
        tree[nod].laz=0;
    }
    if(r<s||e<l) return 1e9;
    if(l<=s&&e<=r){
        return tree[nod].val;
    }
    return min(sol(l,r,s,(s+e)/2,nod*2),
                sol(l,r,(s+e)/2+1,e,nod*2+1));
}
 
vector<ll> d;
ll sum[1010101];
ll cnt[1010101];
vector<ll> v[101010];
ll dx[101010];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
 
    ll i,j,k,l;
    //ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;
 
    //ll t;
    cin>>t;
    while(t--){
        string sans;
        cin>>n>>m;
 
        d.clear();
        for(i=1;i<=m;i++){
            sum[i]=cnt[i]=0;
            v[i].clear();
        }
 
        for(i=1;i<=n;i++)
            cin>>arr[i];
        for(i=1;i<=n*4;i++){
            tree[i].val=tree[i].laz=0;
        }
        sort(arr+1,arr+1+n);
        d.pb((dl)0);
        for(i=1;i<=n;i++)
            d.pb(dl(arr[i]));
 
        for(i=1;i<=m;i++){
            cin>>cnt[i];
            for(j=1;j<=cnt[i];j++){
                //cout<<i<<' '<<j
                cin>>x;
                v[i].pb(x);
                sum[i]+=x;
            }
        }
 
        for(i=1;i<=n;i++)
            upt(i,i,n-i,1,n,1);
 
        for(i=1;i<=m;i++){
            dx[i]=lower_bound(all(d),(sum[i]-1)/cnt[i]+1)-d.begin()-1;
            upt(1,dx[i],-1,1,n,1);
        }
 
 
        
        for(i=1;i<=m;i++){
            for(auto k:v[i]){
                ll ndx=lower_bound(all(d),(sum[i]-k-1)/(cnt[i]-1)+1)-d.begin()-1;
                //cout<<i<<' '<<k<<' '<<sum[i]<<' '<<cnt[i]<<' '<<dx[i]<<' '<<ndx<<'\n';
                if(ndx>dx[i]){
                    upt(dx[i]+1,ndx,-1,1,n,1);
 
                    ll nsol=sol(1,n,1,n,1);
                    if(nsol<0) sans+="0";
                    else sans+="1";
 
                    upt(dx[i]+1,ndx,1,1,n,1);
                }
                else{
                    upt(ndx+1,dx[i],1,1,n,1);
 
                    ll nsol=sol(1,n,1,n,1);
                    if(nsol<0) sans+="0";
                    else sans+="1";
 
                    upt(ndx+1,dx[i],-1,1,n,1);
                }
            }
        }
 
        cout<<sans<<'\n';
    }
}