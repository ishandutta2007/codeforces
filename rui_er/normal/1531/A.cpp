//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const char LOCK[15] = "lock", UNLOCK[15] = "unlock";

int n, sta; char s[15], ans[15] = "blue";
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &n);n;n--) {
		scanf("%s", s);
		if(strcmp(s, LOCK) == 0) sta = 1;
		else if(strcmp(s, UNLOCK) == 0) sta = 0;
		else if(!sta) strcpy(ans, s);
	}
	printf("%s\n", ans);
	return 0;
}