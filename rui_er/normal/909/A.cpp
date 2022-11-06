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

int main() {
	char a[15], b[15];
	scanf("%s%s", a, b);
	int n = strlen(a);
	printf("%c", a[0]);
	rep(i, 1, n-1) if(a[i] < b[0]) printf("%c", a[i]); else break;
	printf("%c\n", b[0]); 
	return 0;
}