// Problem: D. Mark and Lightbulbs
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n;
char s[N], t[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int d, pos;
	Node(int a=0, int b=0) : d(a), pos(b) {}
	friend bool operator < (const Node& a, const Node& b) {
		if(a.d != b.d) return a.d < b.d;
		return a.pos < b.pos;
	}
}a[N], b[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s%s", &n, s+1, t+1);
		if(s[1] != t[1] || s[n] != t[n]) puts("-1");
		else {
			rep(i, 2, n) {
				a[i] = Node(s[i-1] != s[i], i);
				b[i] = Node(t[i-1] != t[i], i);
			}
			sort(a+1, a+1+n);
			sort(b+1, b+1+n);
			ll ans = 0, same = 1;
			rep(i, 1, n) {
				same &= a[i].d == b[i].d;
				if(a[i].pos > b[i].pos) ans += a[i].pos - b[i].pos;
			}
			printf("%lld\n", same?ans:-1);
		}
	}
	return 0;
}