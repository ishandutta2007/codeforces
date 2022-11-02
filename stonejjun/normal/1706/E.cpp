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
string s;
string t;

struct qry{
    ll a,b,s,e;
};
ll par[1010101];

ll ans[1010101];
vector<ll> qq[1010101];
ll l[1010101];
ll r[1010101];
pii edg[1010101];
qry qs[1010101];
vector<ll> gp[1010101];
ll sz[1010101];

ll fi(ll x){
    if(par[x]==x) return x;
    return par[x]=fi(par[x]);
}

ll fil(ll x){
    if(l[x]==x) return x;
    return l[x]=fil(l[x]);
}

ll fir(ll x){
    if(r[x]==x) return x;
    return r[x]=fir(r[x]);
}

void doo(ll x){
    if(fi(x)==fi(x-1)){
        ll lp=fil(x-1);
        ll rp=fir(x);
        l[x]=lp;
        r[x-1]=rp;
        fir(lp);
        fil(rp);
        fil(x);
        fir(x);
    }
    if(fi(x)==fi(x+1)){
        ll lp=fil(x);
        ll rp=fir(x+1);
        l[x+1]=lp;
        r[x]=rp;
        fir(lp);
        fil(rp);
        fil(x);
        fir(x);
    }
    return ;
}

void uf(ll a,ll b){
    a=fi(a);
    b=fi(b);
    if(a==b) return ;
    if(gp[a].size()<gp[b].size()) swap(a,b);

    par[b]=a;

    while(gp[b].size()){
        ll x=gp[b][gp[b].size()-1];
        doo(x);
        gp[a].pb(x);
        gp[b].pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll i,j,k,a,b,c,d,e,f;
        cin>>n>>m>>k;

        for(i=0;i<=n+1;i++){
            par[i]=i;
            l[i]=i;
            r[i]=i;
            gp[i].clear();
        }

        for(i=1;i<=n;i++){
            gp[i].pb(i);
        }

        for(i=1;i<=m;i++){
            qq[i].clear();
        }

        for(i=1;i<=m;i++){
            cin>>edg[i].ff>>edg[i].ss;
        }

        for(i=1;i<=k;i++){
            ans[i]=1e18;
            cin>>qs[i].a>>qs[i].b;
            qs[i].s=0;
            qs[i].e=m+1;
            ll mid=(qs[i].s+qs[i].e)/2;
            if(qs[i].a==qs[i].b) ans[i]=0;
            else qq[mid].pb(i);
        }
        for(ll tt=1;tt<=19;tt++){
            for(i=1;i<=m;i++){
                ll x1=edg[i].ff;
                ll x2=edg[i].ss;
                uf(x1,x2);

          //      for(j=1;j<=n;j++){
           //         cout<<i<<' '<<j<<' '<<l[j]<<' '<<r[j]<<'\n';
            //    }

                for(auto k:qq[i]){
                    if(fir(qs[k].a)>=qs[k].b){
                        ans[k]=min(ans[k],i);
                        qs[k].e=i;
                    }
                    else{
                        qs[k].s=i+1;
                    }
                }
                qq[i].clear();
            }

            for(i=1;i<=k;i++){
                ll mid=(qs[i].s+qs[i].e)/2;
                if(qs[i].a!=qs[i].b&&qs[i].s<qs[i].e) qq[mid].pb(i);
            }

            for(i=0;i<=n+1;i++){
                par[i]=i;
                l[i]=i;
                r[i]=i;
                gp[i].clear();
            }

            for(i=1;i<=n;i++){
                gp[i].pb(i);
            }

        }

        for(i=1;i<=k;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';

    }
}