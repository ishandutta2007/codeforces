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

int n, k, x, y;
bool interact(int x, int y) {
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	char c[4];
	scanf("%s", c);
	return c[0] == 'T';
}
void give(int x, int y) {
	printf("2 %d %d\n", x, y);
	fflush(stdout);
}
int binarySearch(int l, int r) {
	while(l < r) {
		int mid = (l + r) >> 1;
		if(interact(mid, mid+1)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	scanf("%d%d", &n, &k);
	x = binarySearch(1, n);
	y = binarySearch(1, x-1);
	if(!(x ^ y) || !interact(y, x)) y = binarySearch(x+1, n);
	give(x, y);
	return 0;
}