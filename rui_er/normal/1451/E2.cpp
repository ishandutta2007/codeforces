//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1<<16;

int n, a[N+5], vis[N+5], sm[2], ss[3];
int interact(int op, int x, int y) {
	printf("%s %d %d\n", op==1?"AND":(op==2?"OR":"XOR"), x, y);
	fflush(stdout); int res; scanf("%d", &res); return res;
}

int main() {
	scanf("%d", &n); vis[0] = 1;
	rep(i, 2, n) {
		a[i] = interact(3, 1, i);
		if(vis[a[i]]) sm[0] = vis[a[i]], sm[1] = i;
		else vis[a[i]] = i;
		ss[(a[i]==1||a[i]==2)?a[i]:0] = i;
	}
	if(sm[0]) a[1] = interact(1, sm[0], sm[1]) ^ a[sm[0]];
	else a[1] = interact(1, 1, ss[1]) + (interact(1, 1, ss[2]) & 1);
	rep(i, 2, n) a[i] ^= a[1];
	printf("! "); rep(i, 1, n) printf("%d ", a[i]); puts(""); fflush(stdout);
	return 0;
}