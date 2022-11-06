//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T, n, k;
char s[N], t[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%s", &n, &k, s+1);
		int ok = 1;
		rep(i, 1, k) t[i] = '?';
		rep(i, 1, n) {
			if(s[i] == '?') continue;
			if(t[(i-1)%k+1] == '?') t[(i-1)%k+1] = s[i];
			else if(t[(i-1)%k+1] != '?' && s[i] != t[(i-1)%k+1]) {ok = 0; break;}
		}
		if(!ok) {puts("NO"); continue;}
		int que = 0, sum = 0;
		rep(i, 1, k) {
			if(t[i] == '?') ++que;
			else sum += t[i] - '0';
		}
		if(sum <= k / 2 && sum + que >= k / 2) puts("YES");
		else puts("NO");
	}
	return 0;
}