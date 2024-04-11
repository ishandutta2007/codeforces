//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int a[6], s, ok;

int main() {
	rep(i, 0, 5) scanf("%d", &a[i]), s += a[i];
	if(s & 1) return puts("NO"), 0;
	sort(a, a+6);
	do if(a[0] + a[1] + a[2] == s / 2) ok = 1; while(next_permutation(a, a+6) && !ok);
	puts(ok?"YES":"NO");
	return 0;
}