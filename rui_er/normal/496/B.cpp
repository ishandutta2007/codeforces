//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n;
char s[N], t[N], ans[N];

int main() {
	scanf("%d%s", &n, s);
	strcpy(ans, s);
	rep(i, 0, n-1) {
		rep(j, 0, n-1) t[(j+i)%n] = s[j];
		int diff = t[0] - '0';
		rep(j, 0, n-1) {
			t[j] -= diff;
			if(!isdigit(t[j])) t[j] += 10;
		}
		if(strcmp(ans, t) > 0) strcpy(ans, t);
	}
	printf("%s\n", ans);
	return 0;
}