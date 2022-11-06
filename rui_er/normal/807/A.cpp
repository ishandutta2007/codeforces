//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, a[N], b[N], ok = 1;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &a[i], &b[i]);
		if(a[i] ^ b[i]) return puts("rated"), 0;
		ok &= i == 1 || a[i] <= a[i-1];
	}
	puts(ok?"maybe":"unrated");
	return 0;
}