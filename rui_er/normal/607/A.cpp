// Problem: CF607A Chain Reaction
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF607A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 1e6+5;

int n, dp[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int a, b;
	Node(int a=0, int b=0) : a(a), b(b) {}
	friend bool operator < (const Node& a, const Node& b) {return a.a < b.a;}
}a[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a+1, a+1+n);
	int ans = n - 1;
	rep(i, 2, n) {
		int d = a[i].a - a[i].b;
		if(a[i-1].a < d) dp[i] = dp[i-1];
		else {
			int tmp = lower_bound(a+1, a+1+n, Node(d, 0)) - a;
			dp[i] = dp[tmp-1] + i - tmp;
		}
		chkmin(ans, n-i+dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}