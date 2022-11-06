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
const int N = 1e5+5;

int n, a[N], _;
int interact(int x) {
	if(a[x]) return a[x];
	++_;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	return 0;
}

int main() {
	scanf("%d", &n);
	a[0] = a[n+1] = 0x3f3f3f3f;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		a[mid] = interact(mid);
		a[mid-1] = interact(mid-1);
		a[mid+1] = interact(mid+1);
		if(a[mid] < a[mid-1] && a[mid] < a[mid+1]) return give(mid);
		if(a[mid] > a[mid-1]) r = mid - 1;
		else l = mid + 1; 
	}
	return give(l);
}