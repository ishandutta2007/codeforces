#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
//#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1100000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
//const int dr[]={1,0,-1,0,1,1,-1,-1,0};
//const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const int dr[]={1,1,0,0};
const int dc[]={1,0,1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;

int tc,n,m,nr,nc;
bool x[MAX][MAX];
vector<vector<int>> ans;
vector<int> tmp,bf;
char c;

inline void upd(int r,int c,int ty){
	tmp.clear();
	rep(i,0,3)if(i!=ty){
		nr = r+dr[i], nc = c+dc[i];
		tmp.pb(nr), tmp.pb(nc);
		x[nr][nc]^= 1;
	}
	ans.pb(tmp);
	return;
}
inline void jk(int r,int c,int ty){
	rep(i,0,3)if(i!=ty){
		nr = r+dr[i], nc = c+dc[i];
		x[nr][nc]^= 1;
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,3)bf.pb(i);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n)rep(j,1,m)cin>>c, x[i][j] = c=='1';
    	if(m&1){
    		rep(i,2,n){
    			if(x[i-1][m]){
    				if(x[i][m])upd(i-1,m-1,1);
					else upd(i-1,m-1,0);
				}
				else if(x[i][m])upd(i-1,m-1,2);
    			++i;
			}
		}
		if(n&1){
    		rep(j,2,m){
    			if(x[n][j-1]){
    				if(x[n][j])upd(n-1,j-1,2);
					else upd(n-1,j-1,0);
				}
				else if(x[n][j])upd(n-1,j-1,1);
    			++j;
			}
		}
		if((n&1) && (m&1)){
			if(x[n][m]){
				upd(n-1,m-1,0);
				upd(n-1,m-1,3);
			}
		}
		if(n&1)--n;
		if(m&1)--m;
		
//		rep(i,1,n){
//			rep(j,1,m)cout<<x[i][j]; cout<<endl;
//		}
		bool st;
		int mv;
		rep(i,1,n){
			rep(j,1,m){
				sort(all(bf));
				mv = -1;
				do{
					st = 0;
					rep(o,0,4){
						st = 1;
						rep(a,0,1)rep(b,0,1)if(x[i+a][j+b])st = 0;
						if(st){
							mv = o-1;
							break;
						}
						if(o!=4)jk(i,j,bf[o]);
					}
					if(st){
						rep(o,0,mv)upd(i,j,bf[o]);
						rep(o,0,mv)jk(i,j,bf[o]);
						break;
					}
					else rep(o,0,3)jk(i,j,bf[o]);
				}while(next_permutation(all(bf)));
				++j;
			}
			++i;
		}
//		cout<<"RES\n";
//		rep(i,1,n){
//			rep(j,1,m)cout<<x[i][j]; cout<<endl;
//		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			for(auto j:i)cout<<j<<' ';
			cout<<endl;
		}
		ans.clear();
	}
	return 0;
}