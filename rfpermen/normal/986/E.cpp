#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
//#define lc (id<<1)
//#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int cnt,dv,pr[MAX*100],nw;
int n,qu,a,b,c,x[MAX],y[MAX],lc[MAX],bt,dep[MAX],sp[18][MAX];
ll ans[MAX];
vi v[MAX],V[MAX];
map<int,vi> p,q,P,Q;

void dfs(int nw,int par){
	for(int i:v[nw])if(i!=par){
		V[nw].pb(i);
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		dfs(i,nw);
	}
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	rap(i,bt,0)if(dep[x]-(1<<i)>=dep[y])x = sp[i][x];
	if(x==y)return x;
	rap(i,bt,0)if(sp[i][x]!=sp[i][y]){
		x = sp[i][x];
		y = sp[i][y];
	}
	return sp[0][x];
}

bool st[MAX];
int res[MAX];
vector<int> z[MAX];
void f(int nw){
	if(st[nw])++cnt;
	for(int i:z[nw]){
		if(i<0)res[-i]-= cnt;
		else res[i]+= cnt;
	}
	for(int i:v[nw])f(i);
	if(st[nw])--cnt;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,2,3162)if(!pr[i]){
    	rip(j,i,10000000,i)pr[j] = i;
	}
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dep[1] = 1;
	dfs(1,0);
	rep(i,1,n)bt = max(dep[i],bt), v[i] = V[i];
	bt = log2(bt);
	rep(i,1,bt)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]];
	
	rep(i,1,n){
		cin>>c;
		while(pr[c]){
			dv = pr[c], nw = 1;
			while(c%dv==0){
				c/= dv;
				nw*= dv;
				p[nw].pb(i);
			}
			P[nw].pb(i);
		}
		if(c!=1)p[c].pb(i), P[c].pb(i);
	}
	
	cin>>qu;
	rep(i,1,qu){
		ans[i] = 1;
		cin>>x[i]>>y[i]>>c;
		while(pr[c]){
			dv = pr[c], nw = 1;
			while(c%dv==0){
				if(nw!=1)Q[nw].pb(i);
				c/= dv;
				nw*= dv;
			}
			q[nw].pb(i);
		}
		if(c!=1)q[c].pb(i);
		lc[i] = lca(x[i],y[i]);
	}
	
	ll sz;
	rep(i,2,10000000){
		if(p.count(i) && q.count(i)){
			sz = (ll)p[i].size() * q[i].size();
			if(sz*bt*2<=n){
				for(int k:q[i])for(int j:p[i])if(dep[j]>=dep[lc[k]]){
					if(j==lc[k])ans[k] = ans[k]*i%MOD;
					else {
						a = lca(j,x[k]);
						if(a!=j)a = lca(j,y[k]);
						if(a==j)ans[k] = ans[k]*i%MOD;
					}
				}
			}
			else {
				for(int k:q[i]){
					z[x[k]].pb(k);
					z[y[k]].pb(k);
					z[lc[k]].pb(-k);
					if(lc[k]!=1)z[sp[0][lc[k]]].pb(-k);
				}
				for(int k:p[i])st[k] = 1;
				f(1);
				for(int k:p[i])st[k] = 0;
				for(int k:q[i]){
					ans[k] = ans[k]*pw(i,res[k])%MOD;
					res[k] = 0;
					z[x[k]].clear();
					z[y[k]].clear();
					z[lc[k]].clear();
					if(lc[k]!=1)z[sp[0][lc[k]]].clear();
				}
			}
		}
		
		if(P.count(i) && Q.count(i)){
			sz = (ll)P[i].size() * Q[i].size();
			if(sz*bt*2<=n){
				for(int k:Q[i])for(int j:P[i])if(dep[j]>=dep[lc[k]]){
					if(j==lc[k])ans[k] = ans[k]*i%MOD;
					else {
						a = lca(j,x[k]);
						if(a!=j)a = lca(j,y[k]);
						if(a==j)ans[k] = ans[k]*i%MOD;
					}
				}
			}
			else {
				for(int k:Q[i]){
					z[x[k]].pb(k);
					z[y[k]].pb(k);
					z[lc[k]].pb(-k);
					if(lc[k]!=1)z[sp[0][lc[k]]].pb(-k);
				}
				for(int k:P[i])st[k] = 1;
				f(1);
				for(int k:P[i])st[k] = 0;
				for(int k:Q[i]){
					ans[k] = ans[k]*pw(i,res[k])%MOD;
					res[k] = 0;
					z[x[k]].clear();
					z[y[k]].clear();
					z[lc[k]].clear();
					if(lc[k]!=1)z[sp[0][lc[k]]].clear();
				}
			}
		}
		
	}
	rep(i,1,qu)cout<<ans[i]<<endl;
	return 0;
}