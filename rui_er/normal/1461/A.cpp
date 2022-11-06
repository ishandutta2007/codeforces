//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int T, n, veryImportantVariable;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &veryImportantVariable);
		rep(i, 0, n-1) putchar('a'+(i%3)); puts("");
	}
	return 0;
}