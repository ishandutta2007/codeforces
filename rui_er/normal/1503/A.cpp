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
const int N = 2e5+5;

int n, s[N];
char a[N], b[N];
bool check(char* s) {
	int now = 0, len = strlen(s);
	rep(i, 0, len-1) {
		if(s[i] == '(') ++now;
		else --now;
		if(now < 0) return 0;
	}
	return !now;
}
void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%1d", &s[i]);
	a[n+1] = b[n+1] = '\0';
	int sA = 0, sB = 0;
	rep(i, 1, n) {
		if(s[i]) ++sA, ++sB, a[i] = b[i] = '(';
		else if(sA < sB) ++sA, --sB, a[i] = '(', b[i] = ')';
		else --sA, ++sB, a[i] = ')', b[i] = '(';
		if(sA < 0 || sB < 0) {puts("NO"); return;}
	}
	if(sA ^ sB) {puts("NO"); return;}
	int qwq = sA >> 1, now = n;
	rep(i, 1, qwq) {
		while(now >= 1 && !s[now]) --now;
		if(!now) {puts("NO"); return;}
		a[now] = b[now] = ')'; --now;
	}
	if(!check(a+1) || !check(b+1)) {puts("NO"); return;}
	printf("YES\n%s\n%s\n", a+1, b+1);
}

int main() {
	mulT0 solve();
	return 0;
}