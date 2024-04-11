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
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;

int tc,n,cnt,k,mn,opt,cl,vs[MAX][MAX];
char x[MAX][MAX],ans[MAX][MAX];
bool vis[MAX][MAX],tmp[MAX][MAX],vis2[MAX][MAX];

inline bool ins(int r,int c){
	return r>0&&c>0&&r<=n&&c<=n;
}
void del(int r,int c){
	vis[r][c] = vis2[r][c] = 0;
	if(tmp[r][c])ans[r][c] = 'X';
	else ans[r][c] = 'O';
	int nr,nc;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(vis[nr][nc])del(nr,nc);
	}
	return;
}
void gd(int r,int c){
	if(!tmp[r][c]){
		tmp[r][c] = 1;
		bool st;
		rep(i,-2,0)if(r+i>0 && r+i+2<=n){
			st = 1;
			rep(j,0,2)if(!tmp[r+i+j][c])st = 0;
			if(st)break;
		}
		if(st)tmp[r][c] = 0, ++cnt;
		else {
			rep(i,-2,0)if(c+i>0 && c+i+2<=n){
				st = 1;
				rep(j,0,2)if(!tmp[r][c+i+j])st = 0;
				if(st)break;
			}
			if(st)tmp[r][c] = 0, ++cnt;
		}
	}
	vis2[r][c] = 0;
	int nr,nc;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(vis2[nr][nc])gd(nr,nc);
	}
	return;
}
void isi(int r,int c){
	tmp[r][c] = (((r-c)%3+3)%3!=k);
	vs[r][c] = cl;
	vis2[r][c] = 1;
	int nr,nc;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(vis[nr][nc] && vs[nr][nc]!=cl)isi(nr,nc);
	}
	return;
}
void dfs(int r,int c){
	vis[r][c] = 1;
	int nr,nc;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(ins(nr,nc) && !vis[nr][nc] && x[nr][nc]=='X')dfs(nr,nc);
	}
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("xot.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)rep(j,1,n){
    		cin>>x[i][j];
    		if(x[i][j]=='.')ans[i][j] = '.';
    		else ans[i][j] = 0;
		}
    	rep(i,1,n)rep(j,1,n)if(!ans[i][j]){
    		dfs(i,j);
//    			cout<<"\n";
//    		rep(a,1,n){
//    			rep(b,1,n)cout<<vis[a][b]; cout<<endl;
//			}
//    			cout<<"\n";
    		mn = MOD;
    		rep(o,0,2){
    			k = o;
    			++cl, isi(i,j);
    			cnt = 0;
    			gd(i,j);
    			if(cnt<mn)mn = cnt, opt = o;
			}
//			cout<<">> "<<mn<<' '<<opt<<endl;
			k = opt, ++cl, isi(i,j), gd(i,j);
			del(i,j);
		}
		rep(i,1,n){
			rep(j,1,n)cout<<ans[i][j]; cout<<endl;
		}
	}
    return 0;
}