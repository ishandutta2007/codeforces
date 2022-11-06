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

char s[N], a[N], b[N];

int main() {
	mulT0 {
		scanf("%s", s+1);
		int n = strlen(s+1), LA = 0, LB = 0;
		rep(i, 1, n) {
			if((s[i] - 'a') & 1) a[++LA] = s[i];
			else b[++LB] = s[i];
		}
		a[LA+1] = b[LB+1] = '\0';
		sort(a+1, a+1+LA);
		sort(b+1, b+1+LB);
		if(abs(a[LA] - b[1]) != 1) printf("%s%s\n", a+1, b+1);
		else if(abs(b[LB] - a[1]) != 1) printf("%s%s\n", b+1, a+1);
		else puts("No answer");
	}
	return 0;
}