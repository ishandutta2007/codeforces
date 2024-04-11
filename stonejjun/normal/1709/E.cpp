#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=998244353;
ll par[1010101];
ll arr[1010101];
vector<ll> v[1010101];
ll dep[1010101];
ll brr[1010101];
ll gap[1010101];
ll pre[1010101];
set<ll> s[1010101];
ll chk[1010101];

ll ans=0;

void dfs(ll x){
    for(auto k:v[x]){
        if(dep[k]) continue;
        dep[k]=dep[x]+1;
        par[k]=x;
        pre[k]=pre[par[k]]^arr[k];
        dfs(k);
    }
}

bool sf(ll a,ll b){
    return dep[a]>dep[b];
}

void mer(ll x,ll p){
    ll i,j,k,fl=0,c=0;
    if(s[x].size()>s[p].size()){
        swap(s[x],s[p]);
    }

    for(auto it=s[x].begin();it!=s[x].end();it++){
        if(s[p].find((*it)^arr[p]) != s[p].end() ){
            c=1;
            break;
        }
    }

    if(c){
        chk[p]=1;
        ans++;
    }

    for(auto it=s[x].begin();it!=s[x].end();it++){
        s[p].insert(*it);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
   
    ll i,j,k,a,b,c,d,e,f;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        brr[i]=i;
    }

    for(i=1;i<n;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    pre[1]=arr[1];
    dep[1]=1;
    dfs(1);

    sort(brr+1,brr+1+n,sf);

    for(i=1;i<=n;i++){
        s[i].insert(pre[i]);
        //cout<<i<<' '<<pre[i]<<'\n';
    }

    for(i=1;i<n;i++){
        ll x=brr[i];
        ll p=par[x];
        if(chk[x]||chk[p]) continue;
        mer(x,p);
    }

    cout<<ans;


}