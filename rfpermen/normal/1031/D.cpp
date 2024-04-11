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
const int MAX = 2e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={0,1,0,-1,1,1,-1,-1,0};
const int dc[]={-1,0,1,0,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
 
int n,k,z[MAX][MAX];
char x[MAX][MAX];
vector<pii> nw,nx;
char mn;
 
int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	rep(i,1,n)rep(j,1,n)cin>>x[i][j];
	z[1][1] = k;
	nw.pb({1,1});
	rep(iter,2,2*n){
		mn = 'z';
		nx.clear();
		for(auto i:nw){
			if(z[i.fi][i.se]){
				if(mn!='a')nx.clear();
				mn = 'a';
				nx.pb(i);
			}
			else if(x[i.fi][i.se]<=mn){
				if(x[i.fi][i.se]<mn)nx.clear();
				mn = x[i.fi][i.se];
				nx.pb(i);
			}
		}
		cout<<mn;
		nw.clear();
		for(auto i:nx){
			if(z[i.fi][i.se]){
				if(x[i.fi][i.se]!=mn)--z[i.fi][i.se];
				x[i.fi][i.se] = mn;
			}
			if(x[i.fi][i.se] == mn){
				z[i.fi+1][i.se] = max(z[i.fi+1][i.se], z[i.fi][i.se]);
				if(i.fi!=n){
					if(nw.empty() || nw.back()!=mp(i.fi+1,i.se))nw.pb({i.fi+1, i.se});
				}
				z[i.fi][i.se+1] = max(z[i.fi][i.se+1], z[i.fi][i.se]);
				if(i.se!=n) nw.pb({i.fi, i.se+1});
				
			}
		}
	}
	cout<<endl;
	return 0;
}