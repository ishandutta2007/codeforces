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
const int N = 4e5+5;

int n, m, k;
char s[N]; 

int main() {
	mulT0 {
		scanf("%d%d", &n, &m);
		scanf("%s", s+1); k = n + m;
		int ok = 1;
		if((n & 1) && (m & 1)) {puts("-1"); continue;}
		rep(i, 1, k) if(s[i] == '1' && s[k+1-i] == '0' || s[i] == '0' && s[k+1-i] == '1') {puts("-1"); ok = 0; break;}
		if(!ok) continue;
		rep(i, 1, k) if(s[i] != '?') s[k+1-i] = s[i];
		rep(i, 1, k) {
			if(s[i] == '0') --n;
			if(s[i] == '1') --m;
		}
		if(n < 0 || m < 0) {puts("-1"); continue;}
		rep(i, 1, k/2) if(s[i] == '?') {
			if(n > 1) s[i] = s[k+1-i] = '0', n -= 2;
			else s[i] = s[k+1-i] = '1', m -= 2;
		}
		if(k & 1) if(s[k/2+1] == '?') {
			if(n > 0) s[k/2+1] = '0', --n;
			else s[k/2+1] = '1', --m;
		}
		if(!n && !m) printf("%s\n", s+1);
		else puts("-1");
	}
	return 0;
}