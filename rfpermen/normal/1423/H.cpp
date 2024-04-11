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
const int MAX = 5e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,q,k,wk,p[MAX],sz[MAX],op,x,y,a,b;
vii upd[MAX];
bool vis[MAX];
vi del;

int par(int z){
	if(p[z]==z)return z;
	if(!vis[z])vis[z] = 1, del.pb(z);
	return p[z] = par(p[z]);
}

int rp[MAX],rsz[MAX];
int rpar(int z){
	if(rp[z]==z)return z;
	return rp[z] = rpar(rp[z]);
}
int pos;

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q>>k;
	if(k<=block){
		rep(i,1,n)p[i] = i, sz[i] = 1;
		wk = 1;
		while(q--){
			cin>>op;
			if(op==1){
				cin>>a>>b;
				upd[wk].pb({a,b});
				a = par(a), b = par(b);
				if(a!=b){
					if(!vis[a])vis[a] = 1, del.pb(a);
					if(!vis[b])vis[b] = 1, del.pb(b);
					
					p[a] = b;
					sz[b]+= sz[a];
				}
			}
			else if(op==2){
				cin>>a;
				cout<<sz[par(a)]<<endl;
			}
			else {
				++wk;
				if(wk>k){
					for(int i:del)p[i] = i, sz[i] = 1, vis[i] = 0;
					del.clear();
					rep(i,wk-k+1,wk)for(auto &j:upd[i]){
						a = par(j.fi), b = par(j.se);
						if(a!=b){
							if(!vis[a])vis[a] = 1, del.pb(a);
							if(!vis[b])vis[b] = 1, del.pb(b);
							
							p[a] = b;
							sz[b]+= sz[a];
						}
					}
				}
			}
		}
	}
	else {
		rep(i,1,n)p[i] = i, sz[i] = 1;
		wk = 1;
		while(q--){
			cin>>op;
			if(op==1){
				cin>>a>>b;
				upd[wk].pb({a,b});
				a = par(a), b = par(b);
				if(a!=b){
					if(!vis[a])vis[a] = 1, del.pb(a);
					if(!vis[b])vis[b] = 1, del.pb(b);
					
					p[a] = b;
					sz[b]+= sz[a];
				}
			}
			else if(op==2){
				cin>>a;
				cout<<sz[par(a)]<<endl;
			}
			else {
				++wk;
				if(wk>k){
					if((wk-k)%block==1){
						rep(i,1,n)rp[i] = i, rsz[i] = 1;
						mems(vis,0);
						del.clear();
						pos = wk-k+block;
						rep(i,wk-k+block,wk)for(auto &j:upd[i]){
							a = rpar(j.fi), b = rpar(j.se);
							if(a!=b){
								rp[a] = b;
								rsz[b]+= rsz[a];
							}
						}
						rep(i,1,n){
							rp[i] = rpar(i);
							p[i] = rp[i], sz[i] = rsz[i];
						}
					}
					else {
						for(auto &j:upd[wk-1]){
							a = rpar(j.fi), b = rpar(j.se);
							if(a!=b){
								p[a] = rp[a] = b;
								rsz[b]+= rsz[a];
								sz[b] = rsz[b];
							}
						}
						for(int i:del){
							rp[i] = rpar(i);
							p[i] = rp[i], sz[i] = rsz[i], vis[i] = 0;
						}
						del.clear();
					}
					//update belakang
					int lp = (block-(wk-k)%block)%block;
					rep(i,1,lp)for(auto &j:upd[pos-i]){
						a = par(j.fi), b = par(j.se);
						if(a!=b){
							if(!vis[a])vis[a] = 1, del.pb(a);
							if(!vis[b])vis[b] = 1, del.pb(b);
							
							p[a] = b;
							sz[b]+= sz[a];
						}
					}
				}
			}
		}
	}
	return 0;
}