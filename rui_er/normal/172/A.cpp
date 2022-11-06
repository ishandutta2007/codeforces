//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int n, l; char s[30005][25];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%s", s[i]);
	l = strlen(s[1]);
	rep(i, 0, l-1) {
		char u = s[1][i];
		rep(j, 2, n) if(s[j][i] != u) return printf("%d\n", i), 0;
	}
	printf("%d\n", l);
	return 0;
}