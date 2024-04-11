// Problem: C. Coprocessor
// Contest: Codeforces - Training Round #1 (1400-1700-1900-2000-2100-2200, 120min)
// URL: https://codeforces.com/group/iw2l909Oqc/contest/396416/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
const int N = 1e5+5;

int n, m, E[N], deg[N];
vector<int> e[N];
queue<int> qmain, qco;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int toposort() {
	rep(i, 1, n) {
		if(!deg[i]) {
			if(E[i]) qco.push(i);
			else qmain.push(i);
		}
	}
	int cnt = 0;
	while(!qmain.empty() || !qco.empty()) {
		while(!qmain.empty()) {
			int u = qmain.front(); qmain.pop();
			for(int v : e[u]) {
				if(!--deg[v]) {
					if(E[v]) qco.push(v);
					else qmain.push(v);
				}
			}
		}
		if(!qco.empty()) ++cnt;
		while(!qco.empty()) {
			int u = qco.front(); qco.pop();
			for(int v : e[u]) {
				if(!--deg[v]) {
					if(E[v]) qco.push(v);
					else qmain.push(v);
				}
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &E[i]);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		++u; ++v;
		e[v].push_back(u);
		++deg[u];
	}
	printf("%d\n", toposort());
	return 0;
}