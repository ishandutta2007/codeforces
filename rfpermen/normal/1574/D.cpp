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
const int MAX = 1e6+5;
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

ll n,m,x[12][MAX],z[12],k[12],y[12],id,mx;
vector<int> ans,tmp;

struct trie{
	map<int,int> nx;
}tr[MAX];

int nw;
void ins(){
	nw = 0;
	rep(i,1,n){
		if(!tr[nw].nx.count(y[i]))tr[nw].nx[y[i]] = ++id;
		nw = tr[nw].nx[y[i]];
	}
	return;
}

ll val;
void dfs(int i,int nw){
	if(i>n)return;
	rap(j,k[i],1){
		if(tr[nw].nx.count(j)){
			tmp.pb(j);
			val+= x[i][j];
			dfs(i+1,tr[nw].nx[j]);
			val-= x[i][j];
			tmp.pob();
		}
		else {
//			ou3(i,j,val+x[i][j]);
			if(val+x[i][j]+z[i+1]>mx){
				mx = val+x[i][j]+z[i+1];
//				db(i);
//				for(int p:tmp)cout<<p<<" "; cout<<endl;
				ans = tmp;
				ans.pb(j);
				rep(o,i+1,n)ans.pb(k[o]);
			}
			return;
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>k[i];
		rep(j,1,k[i])cin>>x[i][j];
		z[i] = x[i][k[i]];
	}
	rap(i,n,1)z[i]+= z[i+1];
	cin>>m;
	rep(j,1,m){
		rep(i,1,n)cin>>y[i];
		ins();
	}
	dfs(1,0);
	for(int i:ans)cout<<i<<" "; cout<<endl;
	return 0;
}