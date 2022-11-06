//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, nxt[N], ok[N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	nxt[1] = 0;
	rep(i, 2, n) {
		int j = nxt[i-1];
		while(j && s[i] != s[j+1]) j = nxt[j];
		if(s[i] == s[j+1]) ++j;
		nxt[i] = j;
	}
	if(!nxt[n]) return puts("Just a legend")&0;
	rep(i, 2, n-1) ok[nxt[i]] = 1;
	int now = nxt[n];
	while(now && !ok[now]) now = nxt[now];
	if(!now) return puts("Just a legend")&0;
	rep(i, 1, now) putchar(s[i]);
	puts("");
	return 0;
}