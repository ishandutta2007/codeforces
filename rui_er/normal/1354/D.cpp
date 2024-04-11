//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5; 

int n, m, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	int a[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {
		for(;x<=n;x+=lowbit(x)) a[x] += k;
	}
	int ask(int x) {
		int k = 0;
		for(;x;x-=lowbit(x)) k += a[x];
		return k;
	}
}bit;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		bit.add(a[i], 1);
	}
	rep(i, 1, m) {
		scanf("%d", &b[i]);
		if(b[i] > 0) bit.add(b[i], 1);
		else {
			if(bit.ask(n) < -b[i]) continue;
			int L = 1, R = n, ans = n + 1;
			while(R - L >= 5) {
				int M = (L + R) >> 1;
				if(bit.ask(M) >= -b[i]) R = M - 1, ans = M;
				else L = M + 1;
			}
			rep(j, L, R) if(bit.ask(j) >= -b[i]) chkmin(ans, j);
			bit.add(ans, -1);
		}
	}
	rep(i, 1, n) if(bit.ask(i) - bit.ask(i-1)) return printf("%d\n", i)&0;
	puts("0");
	return 0;
}