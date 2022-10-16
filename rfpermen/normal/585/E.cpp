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
const int MAX = 1e7+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={0,1,0,-1,1,1,-1,-1,0};
const int dc[]={-1,0,1,0,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}

vi prime, mb;
int mobius[MAX], composite[MAX];

void sieve(int n){
	mobius[1] = 1;
	fill(composite, composite+1+n, 0);
	rep(i,2,n){
		if(!composite[i]){
			mobius[i] = -1;
			prime.pb(i);
			composite[i] = i;
		}
		if(mobius[i]) mb.pb(i);
		for(int j = 0; j<prime.size() && i * prime[j]<=n; ++j){
			composite[i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				mobius[i * prime[j]] = 0;
				break;
			}
			else {
				mobius[i * prime[j]] = -mobius[i];
			}
		}
	}
	return;
}

int n,a,dv,q,x[500005],pre[500005],cnt[MAX];
ll ans,res,tmp;
vi p,fc;

void bf(int nw,int z){
	if(nw==p.size()){
		if(z!=1)fc.pb(z);
		return;
	}
	bf(nw+1,z);
	bf(nw+1,z*p[nw]);
	return;
}

inline void add(int a){
	p.clear();
	while(a!=1){
		dv = composite[a];
		while(a%dv==0)a/= dv;
		p.pb(dv);
	}
	fc.clear();
	bf(0,1);
	
	for(auto i:fc){
		if(mobius[i]==1){
			++cnt[i];
			ans+= pre[cnt[i]];
		}
		else {
			++cnt[i];
			ans-= pre[cnt[i]];
		}
	}
	ans%= MOD;
}
inline void del(int a){
	p.clear();
	while(a!=1){
		dv = composite[a];
		while(a%dv==0)a/= dv;
		p.pb(dv);
	}
	fc.clear();
	bf(0,1);
	
	for(auto i:fc){
		if(mobius[i]==1){
			ans-= pre[cnt[i]];
			--cnt[i];
		}
		else {
			ans+= pre[cnt[i]];
			--cnt[i];
		}
	}
	ans%= MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sieve(MAX-5);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	pre[1] = 1;
	rep(i,2,500000)pre[i] = (pre[i-1]<<1)%MOD;
	rep(i,1,n)add(x[i]);
	rep(i,1,n){
		del(x[i]);
		tmp = ans;
		add(x[i]);
		res+= ans-tmp*2;
	}
	res+= n;
	res%= MOD;
	if(res<0)res+= MOD;
	cout<<res<<endl;
	return 0;
}