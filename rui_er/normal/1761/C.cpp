// LUOGU_RID: 95055789
// Problem: Set Construction
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1761/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, id[N], deg[N];
char s[N];
vector<int> e[N];
bitset<N> a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void toposort() {
	queue<int> q;
	rep(i, 1, n) {
		a[i][i] = 1;
		if(!deg[i]) q.push(i);
	}
	int tms = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		id[u] = ++tms;
		for(int v : e[u]) {
			if(!--deg[v]) q.push(v);
			a[v] |= a[u];
		}
	}
}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%s", s+1);
			rep(j, 1, n) {
				if(s[j] ^ 48) {
					e[i].push_back(j);
					++deg[j];
				}
			}
		}
		toposort();
		rep(i, 1, n) {
			printf("%d ", (int)a[i].count());
			rep(j, 1, n) if(a[i][j]) printf("%d ", j);
			puts("");
		}
		rep(i, 1, n) {
			e[i].clear();
			id[i] = deg[i] = 0;
			a[i].reset();
		}
	}
	return 0;
}