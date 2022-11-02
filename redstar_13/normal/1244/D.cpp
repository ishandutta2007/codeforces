#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}
using ppi = pair<pii, int>;

const int NN = 100011;
int c[NN][3];
INT dp[NN][3][2];
ppi nxt[NN][3][2];
int res[NN];
const INT inf = 0x3f3f3f3f3f3f3f3fLL;
VI adj[NN];
int out[NN];
bool smin(INT &u, INT v) {return u>v ? u=v, 1 : 0;}

INT dfs(int u, int pre, int i, int j) {
	for(int v : adj[u]) if(v^pre) {
		int k=3-i-j;
		return dfs(v, u, k, i) + c[v][k];
	}
	return 0;
}

void disp(int u, int pre, int i, int j) {
	for(int v : adj[u]) if(v^pre) {
		int k=3-i-j;
		res[v] = k+1;
		return disp(v, u, k, i);
	}
	return ;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	memset(dp, 0x3f, sizeof dp);
	cin >> n;
	for(int i=0; i<3; i++) {
		for(int j=1; j<=n; j++) scanf("%d", c[j]+i);
	}
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
		out[u]++;
		out[v]++;
		if(out[u]==3 or out[v]==3) return puts("-1");
	}
	for(int i=1; i<=n; i++) if(out[i]==1) {
		int u=adj[i][0];
		INT ans=inf;
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) if(j!=k) {
				smin(ans, dfs(u, i, j, k) + c[u][j] + c[i][k]);
			}
		}
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) if(j!=k) {
				if(ans == dfs(u, i, j, k) + c[u][j] + c[i][k]) {
					disp(u, i, j, k);
					res[u] = j+1;
					res[i] = k+1;
					cout << ans << endl;
					for(int i=1; i<=n; i++) printf("%d ", res[i]);
					return 0;
				}
			}
		}
		return 0;
	}
	return 0;
}