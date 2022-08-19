#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1}; //<^>v

int n, m;
int s[35][35];
int t[35][35];
int u[35][35];
int cnt[905];
int used[35][35], ui;
int px[35][35], py[35][35];
vector<P> p;

int x, y;
void bfs(int a, int b) {
	//printf("in %d %d\n",a,b);
	queue<P> q;
	q.push(P(a,b));
	used[a][b] = ++ui;
	px[a][b] = -1;
	while (q.size()) {
		int i = q.front().fi, j = q.front().se; q.pop();
		if (i == x && j == y) break;
		rep(v,8) {
			int ni = i+dx[v], nj = j+dy[v];
			if (ni<0||nj<0||ni>=n||nj>=m||s[ni][nj]==-1||used[ni][nj]==ui) continue;
			used[ni][nj] = ui;
			px[ni][nj] = i;
			py[ni][nj] = j;
			q.push(P(ni,nj));
		}
	}
	/*
	if (used[x][y] != ui) {
		printf("in %d %d\n",a,b);
		printf("out %d %d\n",x,y);
		rep(i,n){rep(j,m)printf("%2d",s[i][j]);puts("");}
		puts("no");
	}//*/
	while (px[x][y] != -1) {
		int i = x, j = y;
		x = px[i][j]; y = py[i][j];
		swap(s[i][j],s[x][y]);
		p.pb(P(x,y));
	}
	//printf("out %d %d\n",x,y);
}
void f() {
	rep(i,n)rep(j,m) if (t[n-1][m-1] == s[i][j]) x = i, y = j;
	p.pb(P(x,y));
	rep(i,n-2) {
		rep(j,m) {
			int a, b;
			rep(ai,n)rep(bi,m) if (s[ai][bi] == t[i][j] && (ai!=x||bi!=y)) a = ai, b = bi;
			s[a][b] = -1;
			while (b > j) {
				bfs(a,b-1);
				swap(s[x][y],s[a][b]);
				swap(y,b);
				p.pb(P(x,y));
			}
			while (b < j) {
				bfs(a,b+1);
				swap(s[x][y],s[a][b]);
				swap(y,b);
				p.pb(P(x,y));
			}
			while (a > i) {
				bfs(a-1,b);
				swap(s[x][y],s[a][b]);
				swap(a,x);
				p.pb(P(x,y));
			}
		}
	} 
	rep(j,m-1) {
		for(int i = n-2; i < n; ++i) {
			int a, b;
			rep(ai,n)rep(bi,m) if (s[ai][bi] == t[i][j] && (ai!=x||bi!=y)) a = ai, b = bi;
			s[a][b] = -1;
			while (a > i) {
				bfs(a-1,b);
				swap(s[x][y],s[a][b]);
				swap(x,a);
				p.pb(P(x,y));
			}
			while (a < i) {
				bfs(a+1,b);
				swap(s[x][y],s[a][b]);
				swap(x,a);
				p.pb(P(x,y));
			}
			while (b > j) {
				bfs(a,b-1);
				swap(s[x][y],s[a][b]);
				swap(b,y);
				p.pb(P(x,y));
			}
		}
	}
	if (x != n-1) p.pb(P(x+1,y));
	printf("%d\n",sz(p)-1);
	rep(i,sz(p)) {
		printf("%d %d\n",p[i].fi+1,p[i].se+1);
	}
}

void check() {
	rep(i,sz(p)-1) {
		swap(u[p[i].fi][p[i].se],u[p[i+1].fi][p[i+1].se]);
	}
	rep(i,n){rep(j,m) printf("%d ",u[i][j]); puts("");}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m) scanf("%d",&s[i][j]);
	rep(i,n)rep(j,m) scanf("%d",&t[i][j]);
	rep(i,n)rep(j,m) cnt[s[i][j]]++;
	rep(i,n)rep(j,m) cnt[t[i][j]]--;
	rep(i,905) if (cnt[i]) {
		puts("-1");
		return 0;
	}
	if (n == 1) {
		rep(si,m){
			rep(i,n)rep(j,m) u[i][j] = s[i][j];
			for (int k = si+1; k < m; ++k) {
				swap(u[0][k],u[0][k-1]);
				bool ok = true;
				rep(i,n)rep(j,m) if(u[i][j] != t[i][j]) ok = false;
				if (ok) {
					printf("%d\n",k-si);
					for(int i = si; i <= k; ++i) {
						printf("%d %d\n",1,i+1);
					}
					return 0;
				}
			}
		}
		rep(si,m){
			rep(i,n)rep(j,m) u[i][j] = s[i][j];
			for (int k = si-1; k >= 0; --k) {
				swap(u[0][k],u[0][k+1]);
				bool ok = true;
				rep(i,n)rep(j,m) if(u[i][j] != t[i][j]) ok = false;
				if (ok) {
					printf("%d\n",si-k);
					for(int i = si; i >= k; --i) {
						printf("%d %d\n",1,i+1);
					}
					return 0;
				}
			}
		}
		puts("-1");
		return 0;
	}
	if (m == 1) {
		rep(si,n){
			rep(i,n)rep(j,m) u[i][j] = s[i][j];
			for (int k = si+1; k < n; ++k) {
				swap(u[k][0],u[k-1][0]);
				bool ok = true;
				rep(i,n)rep(j,m) if(u[i][j] != t[i][j]) ok = false;
				if (ok) {
					printf("%d\n",k-si);
					for(int i = si; i <= k; ++i) {
						printf("%d %d\n",i+1,1);
					}
					return 0;
				}
			}
		}
		rep(si,n){
			rep(i,n)rep(j,m) u[i][j] = s[i][j];
			for (int k = si-1; k >= 0; --k) {
				swap(u[k][0],u[k+1][0]);
				bool ok = true;
				rep(i,n)rep(j,m) if(u[i][j] != t[i][j]) ok = false;
				if (ok) {
					printf("%d\n",si-k);
					for(int i = si; i >= k; --i) {
						printf("%d %d\n",i+1,1);
					}
					return 0;
				}
			}
		}
		puts("-1");
		return 0;
	}

	rep(i,n)rep(j,m) u[i][j] = s[i][j];
	f();
	//check();
	
	return 0;
}