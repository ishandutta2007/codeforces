// Problem: CF234G Practice
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF234G
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

int n;
vector<int> qwq;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int ans = ceil(log2(n));
	printf("%d\n", ans);
	rep(j, 0, ans-1) {
		qwq.clear();
		rep(i, 1, n) if((i >> j) & 1) qwq.push_back(i);
		printf("%u", qwq.size());
		for(int i : qwq) printf(" %d", i);
		puts("");
	}
	return 0;
}