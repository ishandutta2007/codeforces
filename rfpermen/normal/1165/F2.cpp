#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,m,x[MAX],y[MAX],ttl,us,ans,p[MAX],ls[MAX],a,b,c,nw,tmp;
pii z[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i], ttl+= x[i];
    rep(i,1,m)cin>>z[i].fi>>z[i].se, p[i] = i; p[m+1] = m+1;
    sort(z+1,z+1+m);
    ttl<<=1;
    ans = ttl;
    rep(i,1,m){
    	a = z[i].fi, b = z[i].se;
    	if(ans<=a)break;
    	if(ls[b]){
    		tmp = min(y[ls[b]],x[b]);
    		nw = par(ls[b]+1);
    		p[ls[b]] = nw;
    		while(nw<i&&tmp){
    			c = min(x[z[nw].se]-y[nw],tmp);
    			y[nw]+= c, tmp-= c;
    			if(y[nw]==x[z[nw].se])p[nw] = par(nw+1);
    			nw = par(nw+1);
			}
			us-= tmp;
		}
		ls[b] = i;
		c = min(x[b],a-us);
		y[i] = c, us+= c;
		ans = min(ans,max(ttl-us,a));
	}
	cout<<ans<<endl;
    return 0;
}