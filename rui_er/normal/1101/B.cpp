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
const int N = 5e5+5;

int n, L = -1, R = -1, l = -1, r = -1, ans = 4;
char s[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	rep(i, 0, n-1) if(s[i] == '[') {L = i; break;}
	per(i, n-1, 0) if(s[i] == ']') {R = i; break;}
	if(!~L || !~R || L > R) return puts("-1"), 0;
	rep(i, L+1, n-1) if(s[i] == ':') {l = i; break;}
	per(i, R-1, 0) if(s[i] == ':') {r = i; break;}
	if(!~l || !~r || l >= r) return puts("-1"), 0;
	rep(i, l+1, r-1) if(s[i] == '|') ++ans;
	printf("%d\n", ans);
	return 0;
}