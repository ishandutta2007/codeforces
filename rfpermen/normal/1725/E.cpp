#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vlll vector<pll>
#define vvll vector<vll>
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
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pr[MAX];
void init(int n){
	pr[0] = pr[1] = 1;
	for(int i = 2; i<=n; ++i){
		if(pr[i])continue;
		for(int j = i; j<=n; j+=i)pr[j] = i;
	}
	return;
}

int n,x,dv,a,b,sp[19][MAX*2],jk[MAX*2],cv[MAX*2],dep[MAX],dis,st[MAX],id;
vi z[MAX],v[MAX],u[MAX];

void dfs(int nw,int par){
	st[nw] = ++id;
	cv[id] = nw;
	sp[0][id] = st[nw];
	for(int i:u[nw])if(i!=par){
		v[nw].pb(i);
		dep[i] = dep[nw]+1;
		dfs(i,nw);
		sp[0][++id] = st[nw];
	}
}

int X,Y,c;
inline int jarak(int a,int b){
	X = st[a], Y = st[b];
	if(X>Y)swap(X,Y);
	dis = jk[Y-X+1];
	c = min(sp[dis][X], sp[dis][Y-(1<<dis)+1]);
//	out(X,Y);
//	db(sp[dis][X]);
//	db(sp[dis][Y-(1<<dis)+1]);
//	db(dis);
	c = cv[c];
//	db(c);
	return dep[a] + dep[b] - dep[c]*2;
}

ll ans,res,sm[MAX],cnt[MAX];
bool stat[MAX];

void f(int nw){
	sm[nw] = 0;
	cnt[nw] = stat[nw];
	for(int i:v[nw]){
		f(i);
		cnt[nw]+= cnt[i];
		sm[nw]+= sm[i] + cnt[i];
	}
	return;
}

void solve(int nw,int par){
	for(int i:u[nw])if(i!=par && cnt[i]){
		cnt[nw]-= cnt[i];
		sm[nw]-= sm[i] + cnt[i];
		cnt[i]+= cnt[nw];
		sm[i]+= sm[nw] + cnt[nw];
		
		solve(i,nw);
		
		cnt[i]-= cnt[nw];
		sm[i]-= sm[nw] + cnt[nw];
		cnt[nw]+= cnt[i];
		sm[nw]+= sm[i] + cnt[i];
	}
	ll cor = 0, al = cnt[nw] - stat[nw];
	if(stat[nw]){
		for(int i:u[nw])if(cnt[i]){
			ans+= (sm[i] + cnt[i]) * (cnt[nw] - cnt[i] - 1) % MOD;
		}
	}
	for(int i:u[nw])cor+= cnt[i]*cnt[i];
	for(int i:u[nw])if(cnt[i]){
		ans+= ((sm[i] + cnt[i]) * ((al-cnt[i])*(al-cnt[i]) - cor + cnt[i]*cnt[i]) >> 1) % MOD;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init(MAX-5);
	cin>>n;
	rep(i,1,n){
		cin>>x;
		while(x!=1){
			dv = pr[x];
			while(x%dv==0)x/= dv;
			z[dv].pb(i);
		}
	}
	rep(i,2,n){
		cin>>a>>b;
		u[a].pb(b);
		u[b].pb(a);
	}
	dfs(1,0);
	rep(i,0,17)rep(j,1,id-(1<<i))sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
	rep(i,0,18)jk[1<<i] = i;
	rep(i,1,400000)if(!jk[i])jk[i] = jk[i-1];
	rep(i,2,200000)if(z[i].size()>2){
		if(z[i].size()<=block){
			res = 0;
			For(j,0,z[i].size())For(k,j+1,z[i].size()){
				res+= jarak(z[i][j], z[i][k]);
			}
			ans+= res*(z[i].size()-2) >> 1;
		}
		else {
			mems(stat,0);
			for(int j:z[i])stat[j] = 1;
			f(1);
			solve(1,0);
		}
		ans%= MOD;
	}
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
	return 0;
}