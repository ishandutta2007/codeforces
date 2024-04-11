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
#define lc (id<<1)
#define rc ((id<<1)|1)
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
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,x[MAX],ans[MAX],cnt[MAX],tmp,hit,y;
vector<pii> v;
vi z[MAX],u[MAX];
unordered_set<int> vis;

inline void del(int x,bool st=0){
	for(pii &i:v){
		tmp = 1;
		rep(j,1,i.se){
			tmp*= i.fi;
			if(x%tmp){
				--cnt[tmp];
				if(st)z[tmp].pob();
				break;
			}
		}
	}
	return;
}

inline void ins(int x,bool st=0){
	for(pii &i:v){
		tmp = 1;
		rep(j,1,i.se){
			tmp*= i.fi;
			if(x%tmp){
				++cnt[tmp];
				if(st)z[tmp].pb(x);
				break;
			}
		}
	}
	return;
}

int ret;
inline int get(){
	ret = 1;
	for(pii &i:v){
		tmp = 1;
		rep(j,1,i.se){
			tmp*= i.fi;
			if(cnt[tmp]){
				ret*= tmp/i.fi;
				break;
			}
			if(j==i.se)ret*= tmp;
		}
	}
	return ret;
} 

void f(int nw,int par,int fpb){
	ans[nw] = fpb;
	vis.clear();
	for(pii &i:v){
		y = 1;
		rep(j,1,i.se){
			y*= i.fi;
			if(z[y].size()){
				if(z[y].size()==1 && !vis.count(z[y][0])){
					vis.insert(z[y][0]);
					del(z[y][0]);
					ans[nw] = max(ans[nw],get());
					ins(z[y][0]);
				}
				break;
			}
		}
	}
	for(int i:u[nw])if(i!=par){
		ins(x[i],1);
		f(i,nw,__gcd(fpb,x[i]));
		del(x[i],1);
	}
	return;
}

void dfs(int nw,int par,int fpb){
	ans[nw] = max(ans[nw],fpb);
	for(int i:u[nw])if(i!=par){
		dfs(i,nw,__gcd(fpb,x[i]));
	}
	return;
}

int a,b;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n){
		cin>>a>>b;
		u[a].pb(b);
		u[b].pb(a);
	}
	tmp = x[1];
	rep(i,2,tmp)if(tmp%i==0){
		hit = 0;
		while(tmp%i==0){
			tmp/= i;
			++hit;
		}
		v.pb({i,hit});
	}
	f(1,0,x[1]);
	dfs(1,0,0);
	rep(i,1,n)cout<<ans[i]<<" "; cout<<endl;
	return 0;
}