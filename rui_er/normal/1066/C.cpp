//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 6e5+5, delta = 3e5; 

int T, q[N], L, R, pos[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	L = delta; R = delta - 1;
	for(scanf("%d", &T);T;T--) {
		char op[3]; int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'L') {
			q[--L] = x;
			pos[x] = L;
		}
		else if(op[0] == 'R') {
			q[++R] = x;
			pos[x] = R;
		}
		else {
			int d = pos[x];
			int ans = min(R-d, d-L);
			printf("%d\n", ans);
		}
	}
	return 0;
}