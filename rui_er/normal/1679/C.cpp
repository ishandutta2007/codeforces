// Problem: C. Rooks Defenders
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/C
// Memory Limit: 256 MB
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

int n, m;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct BIT {
	int c[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] += k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k += c[x]; return k;}
	int Ask(int L, int R) {return ask(R) - ask(L-1);}
}row1, col1, row2, col2;

int main() {
	scanf("%d%d", &n, &m);
	while(m --> 0) {
		int op, x, y, z, w;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			row1.add(x, 1);
			col1.add(y, 1);
			if(row1.Ask(x, x) == 1) row2.add(x, 1);
			if(col1.Ask(y, y) == 1) col2.add(y, 1);
		}
		else if(op == 2) {
			if(row1.Ask(x, x) == 1) row2.add(x, -1);
			if(col1.Ask(y, y) == 1) col2.add(y, -1);
			row1.add(x, -1);
			col1.add(y, -1);
		}
		else {
			scanf("%d%d", &z, &w);
			if(row2.Ask(x, z) == z - x + 1 || col2.Ask(y, w) == w - y + 1) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}