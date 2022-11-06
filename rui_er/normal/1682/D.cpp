// Problem: CF1682D Circular Spanning Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1682D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, vis[N];
char s[N];
vector<int> odd, lst;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s", &n, s);
		odd.clear();
		lst.clear();
		rep(i, 0, n-1) vis[i] = 0;
		rep(i, 0, n-1) if(s[i] == 49) {odd.push_back(i); vis[i] = 1;}
		if(odd.empty() || odd.size() & 1) {puts("NO"); continue;}
		puts("YES");
		auto inc = [](int x) {return (x + 1) % n;};
		auto dec = [](int x) {return (x + n - 1) % n;};
		for(int i : odd) {
			int u;
			for(u=i;!vis[inc(u)];u=inc(u)) {
				vis[inc(u)] = 1;
				printf("%d %d\n", u+1, inc(u)+1);
			}
			lst.push_back(u);
		}
		for(int i : lst) if(i != lst[0]) printf("%d %d\n", lst[0]+1, i+1);
	}
	return 0;
}