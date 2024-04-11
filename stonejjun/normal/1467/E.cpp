#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
//vector<pii> ans;
//ll inf=1e18;
ll day;
ll arr[210101];
ll chk[210101];
ll pans[210101];
ll cnt[210101];
ll vis[210101];
ll dep[210101];
ll brr[210101];
ll par[210101];
ll in[210101];
ll out[210101];
ll ord[210101];

vector<ll> v;
vector<ll> ed[210101];
vector<ll> nds[210101];

ll nchk;

bool sf(ll a,ll b){
    return dep[a]>dep[b];
}

void dfs(ll x){
    nchk++;
    in[x]=nchk;
    vis[x]=1;
    ord[nchk]=arr[x];
    nds[arr[x]].pb(nchk);

    for(auto k:ed[x]){
        if(vis[k]) continue;
        par[k]=x;
        dep[k]=dep[x]+1;
        dfs(k);
    }
    out[x]=nchk;
}
ll isfin=0;
ll fians;

void fidfs(ll x){
    vis[x]=1;
    if(arr[x]) return;
    fians++;
    for(auto k:ed[x]){
        if(vis[k]) continue;
        fidfs(k);
    }
}

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
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        v.pb(arr[i]);
    }
    v.pb(0);

    sort(v.begin(), v.end());
    v.erase(unique(all(v)),v.end());
    for(i=1;i<=n;i++){
        arr[i]=lower_bound(all(v),arr[i])-v.begin();
        cnt[arr[i]]++;
        brr[i]=i;
    }

    for(i=1;i<=n;i++){
        if(cnt[arr[i]]==1) arr[i]=0;
        else if(chk[arr[i]]==0){
            chk[arr[i]]=1;
            cnta++;
        }
    }

    for(i=1;i<n;i++){
        cin>>a>>b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
    dep[1]=1;
    dfs(1);
    ll ans=0;

    ll mdep=0;
    ll mi=0;
    for(i=1;i<=n;i++){
        if(arr[i]==0) continue;
        ll p=upper_bound(all(nds[arr[i]]),out[i])-upper_bound(all(nds[arr[i]]),in[i]);
        //cout<<i<<' '<<dep[i]<<' '<<arr[i]<<' '<<in[i]<<' '<<out[i]<<' '<<p<<'\n';
 //       for(auto k:nds[arr[i]])
  //          cout<<k<<'\n';

        if(p>0&&dep[i]>mdep){
            mdep=dep[i];
            mi=i;
        }
    }  
   //cout<<mi<<'\n';
    if(mi==0){
        for(i=1;i<=n;i++)
            vis[i]=0;
        fidfs(1);
        cout<<fians<<'\n';
        return 0;
    }

    ll rt=0;
    for(auto k:ed[mi]){
        if(k==par[mi]) continue;
        ll p=upper_bound(all(nds[arr[mi]]),out[k])-upper_bound(all(nds[arr[mi]]),in[k]);
        if(p>0){
            rt=k;
            break;
        }
    }
    if(rt==0){
        cout<<0;
        return 0;
    }
    //cout<<rt<<'\n';
    for(i=1;i<=n;i++){
        vis[i]=0;
        dep[i]=0;
        nds[i].clear();
    }
    nchk=0;

    dep[rt]=1;
    dfs(rt);

    for(i=1;i<=n;i++){
        if(arr[i]==0) continue;
        ll p=upper_bound(all(nds[arr[i]]),out[i])-upper_bound(all(nds[arr[i]]),in[i]);
       // cout<<i<<' '<<dep[i]<<' '<<arr[i]<<' '<<in[i]<<' '<<out[i]<<' '<<p<<'\n';
        if(p>0){
            cout<<0;
            return 0;
        }
    }  

    for(i=1;i<=n;i++)
        vis[i]=0;
    fidfs(rt);
    cout<<fians<<'\n';
    

}