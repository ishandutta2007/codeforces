//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 105;

int n, k, len[N], mi, ma;
char str[N][N];

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	scanf("%s", str[n+1]);
	len[n+1] = strlen(str[n+1]);
	rep(i, 1, n) {
		if(len[i] < len[n+1]) ++mi, ++ma;
		else if(len[i] == len[n+1]) ++ma;
	}
	--ma;
	mi = mi + (mi / k) * 5 + 1;
	ma = ma + (ma / k) * 5 + 1;
	printf("%d %d\n", mi, ma);
	return 0;
}