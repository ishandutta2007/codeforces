#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 2111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int f[N], t[N];
int e[N][N], mo[N][N];
vector<int> v[N];
int col[N], sz[N], we[N];
int dp[N];
int kol;
int T = 0, C = 0;
int lol = 0;

void dfs(int x, int p) {
	T++;
	f[x] = t[x] = T;
	for (int i = 0; i < n; i++) if (e[x][i] && i != p) {
		if (!t[i]) {
			dfs(i, x);

			if (f[i] > t[x]) {
				mo[x][i] = mo[i][x] = 1;
			}
			f[x] = min(f[x], f[i]);
		} else {
			f[x] = min(f[x], t[i]);
		}
	}
}

void rec(int x) {
	if (col[x]) return;
	col[x] = C;
	kol++;
	for (int i = 0; i < n; i++) if (e[x][i] && mo[x][i] == 0) {
		rec(i);
	} 
}

void go(int x) {
	if (sz[x]) return;
	sz[x] = we[x];
	for (int i = 0; i < v[x].size(); i++) if (sz[v[x][i]] == 0) {
		go(v[x][i]);
		sz[x] += sz[v[x][i]];
		lol += sz[v[x][i]] * we[x];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x][y] = e[y][x] = 1;	
	}
	
	dfs(0, -1);
//	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (mo[i][j]) cout <<  i << " " << j <<endl;

	for (int i = 0; i < n; i++) if (!col[i]) {
		C++;
		kol = 0;
		rec(i);
		we[C - 1] = kol;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (mo[i][j]) {
		v[col[i] - 1].pb(col[j] - 1);
	}
	int best = 0;
	int ans = 0;
	for (int r = 0; r < C; r++) {
		for (int i = 0; i < n; i++) sz[i] = 0;
		lol = 0;
		go(r);

		for (int i = 0; i <= n; i++) dp[i] = 0;
		dp[0] = 1;
		for (int i = 0; i < v[r].size(); i++) {
			int cur = sz[v[r][i]];
			for (int j = n - 1; j >= 0; j--) if (j + cur < n && dp[j]) dp[j + cur] = 1;
		}
//		int cn = n - we[r];
		for (int i = 0; i < n; i++) if (dp[i]) {
			best = max(best, i * (n - we[r] - i) + lol);
		}			
	}
	for (int i = 0; i < C; i++) {
		ans += we[i] * (we[i] - 1);
	}
	ans += best;
	ans += n;
	cout << ans << endl;


	return 0;
}