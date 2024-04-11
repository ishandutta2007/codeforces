#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,x[MAX][MAX],p[MAX*MAX],id,rmn,rmx,cmn,cmx,a,b;
piiii z[MAX*MAX];
char ch[MAX][MAX];
set<int> s[MAX];
unordered_set<int> cn;
vector<int> del,tmp[MAX],nx,nw;
queue<pii> q;
bool vis[MAX*MAX];

inline void dfs(int r,int c){
	q.push({r,c});
	x[r][c] = id;
	int nr,nc;
	while(!q.empty()){
		r = q.front().fi, c = q.front().se, q.pop();
		rmn = min(rmn,r), rmx = max(rmx,r);
		cmn = min(cmn,c), cmx = max(cmx,c);
		rep(i,0,3){
			nr = r+dr[i], nc = c+dc[i];
			if(!x[nr][nc] && ch[nr][nc]=='.'){;
				x[nr][nc] = id;
				q.push({nr,nc});
			}
		}
	}
	return;
}

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void cek(int r,int c){
	int nr,nc;
	cn.clear();
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(ch[nr][nc]=='.')cn.insert(x[nr][nc]);
	}
	if(!cn.empty()){
		a = *cn.begin();
		cn.erase(a);
		a = par(a);
		for(int i:cn){
			b = par(i);
			if(a!=b){
				if(!vis[a])nx.pb(a), vis[a] = 1;
				p[b] = a;
				z[a].ff = min(z[a].ff,z[b].ff);
				z[a].fs = max(z[a].fs,z[b].fs);
				z[a].sf = min(z[a].sf,z[b].sf);
				z[a].ss = max(z[a].ss,z[b].ss);
			}
		}
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    mems(ch,'*');
    rep(i,1,n)rep(j,1,m){
    	cin>>ch[i][j];
    	if(ch[i][j]=='*')s[i].insert(j);
	}
	rep(i,1,n)rep(j,1,m)if(ch[i][j]=='.' && !x[i][j]){
		++id;
		p[id] = id;
		nx.pb(id);
		vis[id] = 1;
		rmn = rmx = i;
		cmn = cmx = j;
		dfs(i,j);
		z[id] = {{rmn,rmx},{cmn,cmx}};
	}
	auto it = s[1].begin();
	
	int A,B;
	while(!nx.empty()){
		nw = nx;
		nx.clear();
		rep(i,1,n)tmp[i].clear();
		for(int i:nw)if(par(i)==i){
			vis[i] = 0;
			A = z[i].ff, B = z[i].fs;
			rep(j,A,B){
				del.clear();
				if(!s[j].empty()){
					it = s[j].lower_bound(z[i].sf);
					while(it!=s[j].end() && (*it)<=z[i].ss)del.pb(*it), ++it;
				}
				for(int o:del){
					tmp[j].pb(o);
					ch[j][o] = '.';
					x[j][o] = i;
					s[j].erase(o);
				}
			}
		}
		rep(i,1,n)for(int j:tmp[i])cek(i,j);
	}
	
	rep(i,1,n){
		rep(j,1,m)cout<<ch[i][j];
		cout<<endl;
	}
    return 0;
}