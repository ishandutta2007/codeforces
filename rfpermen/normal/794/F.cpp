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

ll n,q,x,y[MAX][10],z[MAX/block+5][10],tmp[10],mul,bc,ans,a,b,le,ri,op,A,B,C,D,st,id;
vector<pii> lz[MAX/block+5];

inline void relax(int bc){
	if(lz[bc].empty())return;
	C = bc*block, D = C+block-1;
	rep(i,C,D){
		for(pii &j:lz[bc]){
			tmp[j.se]+= y[i][j.fi];
			tmp[j.fi]-= y[i][j.fi];
		}
		rep(j,0,9)y[i][j]+= tmp[j], tmp[j] = 0;
	}
	lz[bc].clear();
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,1,n){
		cin>>x;
		mul = 1;
		bc = i/block;
		while(x){
			y[i][x%10]+= mul;
			z[bc][x%10]+= mul;
			mul*= 10, x/= 10;
		}
	}
	while(q--){
		cin>>op>>le>>ri;
		A = le/block, B = ri/block;
		relax(A);
		relax(B);
		
		if(op==1){
			cin>>a>>b;
			if(a==b)continue;
			if(A==B){
				if(!z[A][a])continue;
				rep(i,le,ri){
					z[A][a]-= y[i][a];
					z[A][b]+= y[i][a];
					y[i][b]+= y[i][a];
					y[i][a] = 0;
				}
			}
			else {
				if(z[A][a]){
					D = (A+1)*block-1;
					rep(i,le,D){
						z[A][a]-= y[i][a];
						z[A][b]+= y[i][a];
						y[i][b]+= y[i][a];
						y[i][a] = 0;
					}
				}
				if(z[B][a]){
					C = B*block;
					rep(i,C,ri){
						z[B][a]-= y[i][a];
						z[B][b]+= y[i][a];
						y[i][b]+= y[i][a];
						y[i][a] = 0;
					}
				}
				++A, --B;
				rep(i,A,B)if(z[i][a]){
					if(z[i][b]){
						relax(i);
						lz[i].pb({a,b});
						relax(i);
					}
					else {
						st = -1, id = 0;
						for(pii &j:lz[i]){
							if(j.se==a){
								j.se = b;
								st = id;
								break;
							}
							++id;
						}
						if(st==-1)lz[i].pb({a,b});
						else if(lz[i][id].fi==lz[i][id].se)lz[i].erase(lz[i].begin()+id);
					}
					z[i][b]+= z[i][a];
					z[i][a] = 0;
				}
			}
		}
		else {
			ans = 0;
			if(A==B){
				rep(i,le,ri)rep(j,1,9)ans+= y[i][j]*j;
			}
			else {
				D = (A+1)*block-1;
				rep(i,le,D)rep(j,1,9)ans+= y[i][j]*j;
				C = B*block;
				rep(i,C,ri)rep(j,1,9)ans+= y[i][j]*j;
				
				++A, --B;
				rep(i,A,B)rep(j,1,9)ans+= z[i][j]*j;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}