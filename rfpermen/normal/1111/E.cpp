#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

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
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;

int n,q,k,m,r,x,a,b,sp[18][MAX],dep[MAX],tmp,id,sta[MAX],en[MAX];
ll ans[305],res;
vector<int> v[MAX],u[MAX],nd;
piii e[MAX];
bool st,vis[MAX],qu[MAX];

void dfs(int nw,int par){
	sta[nw] = id+1;
	for(int i:v[nw])if(i!=par){
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		dfs(i,nw);
	}
	en[nw] = ++id;
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])tmp = x, x = y, y = tmp;
	rap(i,16,0)if(dep[x]-(1<<i)>=dep[y])x = sp[i][x];
	if(x==y)return x;
	
	rap(i,16,0){
		if(sp[i][x]!=sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

inline int dist(int x,int y){
	return dep[x] + dep[y] - (dep[lca(x,y)]<<1);
}

void comp(int nw,int par){
	vis[nw] = 1;
	for(int i:v[nw])if(!vis[i]){
		if(qu[i])u[par].pb(i), comp(i,i);
		else comp(i,par);
	}
	return;
}

ll fc[305], pre[305], pr[305][305];
inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll f(int nw,int rem){
	if(!rem)return 0;
	ll ret = rem;
	for(int i:u[nw])ret = ret*f(i,rem-1)%MOD;
	return ret;
}

vector<int> o[MAX],isi,at,bw;
int sz;

bool cmp(int a,int b){
	return dep[a]<dep[b];
}

int le,ri,mid,par[MAX],mn[MAX],rt;

int main(){
//	cout<<fixed<<setprecision(5);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fc[0] = pre[0] = 1;
    rep(i,1,300)fc[i] = fc[i-1]*i%MOD, pre[i] = pw(fc[i],MOD-2);
    rep(i,0,300)rep(j,0,i)pr[i][j] = fc[i] * pre[j] % MOD * pre[i-j] % MOD;
    
    cin>>n>>q;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dep[1] = 1;
	dfs(1,0);
	rep(j,1,16)rep(i,1,n)sp[j][i] = sp[j-1][sp[j-1][i]];
	
	while(q--){
		cin>>k>>m>>r;
		st = 0;
		
		if(k>=block){
			memset(vis,0,sizeof vis);
			memset(qu,0,sizeof qu);
			rep(i,1,k){
				cin>>x;
				if(x==r)st = 1;
				qu[x] = 1;
			}
			rep(i,1,n)u[i].clear();
			comp(r,r);
		}
		else {
			nd.clear();
			rep(i,1,k){
				cin>>x;
				if(x==r)st = 1;
				nd.pb(x);
			}
			if(!st)nd.pb(r);
			else --k;
			
			for(int i:nd)u[i].clear(), par[i] = 0, mn[i] = MOD;
			at.clear(), bw.clear();
			
			for(int i:nd){
				tmp = lca(r,i);
				
				if(tmp==i)at.pb(i);
				else if(tmp==r)bw.pb(i);
				else {
					if(o[tmp].empty())isi.pb(tmp);
					o[tmp].pb(i);
				}
			}
			
			sort(all(at),cmp);
			sz = at.size()-1;
			
			rep(i,1,sz)u[at[i]].pb(at[i-1]);
			
			for(int i:isi){
				le = 0, ri = sz;
				while(le<=ri){
					mid = le+ri>>1;
					if(dep[i]<=dep[at[mid]])rt = at[mid], ri = mid-1;
					else le = mid+1;
				}
				for(int j:o[i])for(int l:o[i]){
					if(l!=j){
						if(en[l]>=sta[j]&&en[l]<en[j]&&mn[l]>en[j]-sta[j]){
							mn[l] = en[j]-sta[j], par[l] = j;
						}
					}
				}
				for(int j:o[i]){
					if(par[j])u[par[j]].pb(j);
					else u[rt].pb(j);
				}
				o[i].clear();
			}
			isi.clear();
			
			for(int j:bw)for(int l:bw){
				if(l!=j){
					if(en[l]>=sta[j]&&en[l]<en[j]&&mn[l]>en[j]-sta[j]){
						mn[l] = en[j]-sta[j], par[l] = j;
					}
				}				
			}
			for(int j:bw){
				if(par[j])u[par[j]].pb(j);
				else u[r].pb(j);
			}
		}
		
		res = 0;
		if(st){
			rep(i,1,m){
				ans[i] = f(r,i);
				rap(j,i-1,1)ans[i]-= ans[j]*pr[i][j]%MOD;
				ans[i]%=MOD;
			}
		}
		else {
			rep(i,1,m){
				ans[i] = 1;
				for(int j:u[r])ans[i] = ans[i]*f(j,i)%MOD;
				rap(j,i-1,1)ans[i]-= ans[j]*pr[i][j]%MOD;
				ans[i]%=MOD;
			}
		}
		
//		for(int i:nd)
//		rep(i,1,n)
//		{
//			if(u[i].empty())continue;
//			cout<<i<<" = ";
//			for(int j:u[i])cout<<j<<' '; cout<<endl;
//		}
//		db(st);
//		cout<<">> "; rep(i,1,m)cout<<ans[i]*pre[i]%MOD<<' '; cout<<endl;
		
		rep(i,1,m)res = (res + ans[i]*pre[i])%MOD;
		if(res<0)res+= MOD;
		cout<<res<<endl;
	}
	return 0;
}