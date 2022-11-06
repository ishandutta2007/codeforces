// Problem: CF1534D Lost Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1534D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N = 2e3+5;

int n, dis[N];
vector<int> nd[2], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void ask(int u) {
	printf("? %d\n", u);
	fflush(stdout);
	rep(i, 1, n) scanf("%d", &dis[i]);
}
void give() {
	puts("!");
	rep(u, 1, n) {
		for(int v : ans[u]) {
			if(v == 1) continue;
			printf("%d %d\n", u, v);
		}
	}
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	ask(1);
	rep(i, 2, n) if(dis[i] == 1) ans[1].push_back(i);
	rep(i, 2, n) nd[dis[i]&1].push_back(i);
	int k = nd[0].size() < nd[1].size() ? 0 : 1;
	for(int u : nd[k]) {
		ask(u);
		rep(v, 1, n) if(dis[v] == 1) ans[u].push_back(v);
	}
	give();
	return 0;
}