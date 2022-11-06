//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int T, n, m;
char s[N], t[N], qwq[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
bool check(int a, int b) {return s[a] == t[b];}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s%s", s+1, t+1);
		n = strlen(s+1); m = strlen(t+1);
		int ok = 0;
		rep(i, 1, n) {
			rep(R, i, n) {
				int tot = 0, now = R;
				rep(j, i, R) qwq[++tot] = s[j];
				if(tot > m) break;
				while(tot < m) qwq[++tot] = s[--now];
				qwq[++tot] = '\0';
				if(!strcmp(t+1, qwq+1)) {ok = 1; break;}
			}
			if(ok) break;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}

/*
Hack

Extra Test #1 (FAILED)

Input:
1
ababcababcabababc
bcababacba

Output:
NO

Expected:
YES

Rejudge:
YES
*/