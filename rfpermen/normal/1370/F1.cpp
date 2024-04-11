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
//#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1010205047;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;

int tc,sz,n,a,b,vis[MAX][MAX],ds,x,y,mn;
bool z[MAX];
set<int> s;
vector<int> v[MAX],cnd,qu;
vector<pii> tmp;
string res;

void f(int nw,int par){
	for(int i:v[nw])if(i!=par){
		vis[a][i] = vis[a][nw]+1;
		f(i,nw);
	}
	return;
}

inline void que(){
	cout<<"? "<<qu.size();
	for(int i:qu)cout<<' '<<i; cout<<endl;
	cin>>x>>y;
	return;
}

bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)v[i].clear();
    	memset(vis,-1,sizeof vis);
    	rep(i,2,n){
    		cin>>a>>b;
    		v[a].pb(b), v[b].pb(a);
		}
		rep(i,1,n)a = i, vis[a][a] = 0, f(a,0);
		
		memset(z,0,sizeof z);
		qu.clear();
		rep(i,1,n)qu.pb(i);
		que();
		cnd.clear();
		cnd.pb(x), ds = y;
		
		rep(coba,1,13){
			s.clear();
			rep(i,1,n)if(!z[i]){
				rep(j,i+1,n)if(!z[j]){
					st = 1;
					for(int k:cnd)if(vis[i][k]+vis[k][j]!=ds){
						st = 0;
						break;
					}
					if(st)s.insert(i), s.insert(j);
				}
			}
			for(int i:cnd)if(s.count(i))s.erase(i);
			
			tmp.clear();
			for(int i:s){
				mn = n;
				for(int j:cnd)mn = min(mn, vis[i][j]);
				tmp.pb({mn,i});
			}
			if(tmp.empty())break;
			sort(all(tmp));
			reverse(all(tmp));
			sz = tmp.size()/2;
			qu.clear();
			rep(i,0,sz)qu.pb(tmp[i].se);
			que();
			if(y!=ds){
				for(int i:qu)z[i] = 1;
			}
			else cnd.pb(x);
		}
		
		st = 0;
		for(int i:cnd){
			for(int j:cnd)if(vis[i][j]==ds){
				st = 1;
				cout<<"! "<<i<<' '<<j<<endl;
				cin>>res;
			}
			if(st)break;
		}
		if(!st||res[0]=='I')return 1;
	}
	return 0;
}