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

int n, totD, totR, banD, banR;
char s[N];
queue<int> q;

int main() {
	scanf("%d%s", &n, s+1);
	rep(i, 1, n) {
		q.push(s[i]=='D');
		if(s[i] == 'D') ++totD;
		else ++totR;
	}
	while(totD && totR) {
		int now = q.front(); q.pop();
		if(now) {
			if(banR) --totD, --banR;
			else q.push(1), ++banD;
		}
		else {
			if(banD) --totR, --banD;
			else q.push(0), ++banR;
		}
	}
	printf("%c\n", "RD"[!!totD]);
	return 0;
}