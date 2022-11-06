//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;
const int nxt[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m, dp[N*N], indeg[N*N];
char s[N][N];
vector<int> e[N*N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int getId(int x, int y) {return (x - 1) * m + y;}
bool suc(char x, char y) {
	if(x == 'D' && y == 'I') return 1;
	if(x == 'I' && y == 'M') return 1;
	if(x == 'M' && y == 'A') return 1;
	if(x == 'A' && y == 'D') return 1;
	return 0;
}
bool toposort() {
	queue<int> q;
	int tot = 0;
	rep(i, 1, n*m) {
		if(!indeg[i]) {
			q.push(i);
			++tot;
		}
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[u]) {
			if(!--indeg[v]) {
				q.push(v);
				++tot;
				chkmax(dp[v], dp[u] + 1);
			}
		}
	}
	return tot == n * m;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i]+1);
	rep(i, 1, n) {
		rep(j, 1, m) {
			if(s[i][j] == 'D') dp[getId(i, j)] = 1;
			rep(_, 0, 3) {
				int I = i + nxt[_][0], J = j + nxt[_][1];
				if(I < 1 || I > n || J < 1 || J > m || !suc(s[i][j], s[I][J])) continue;
				e[getId(i, j)].push_back(getId(I, J));
				++indeg[getId(I, J)];
			}
		}
	}
	if(!toposort()) return puts("Poor Inna!")&0;
	int mx = *max_element(dp+1, dp+1+n*m);
	if(mx / 4) printf("%d\n", mx / 4);
	else puts("Poor Dima!");
	return 0;
}