//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 256;

int n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s);
	n = strlen(s);
	int now = 0, ans = 0, tag = 1;
	rep(i, 0, n-1) {
		if(isdigit(s[i])) now = 10 * now + s[i] - 48;
		else {
			ans += tag * now;
			now = s[i] - 48;
			tag = s[i] == '+' ? 1 : -1;
		}
	}
	ans += tag * now;
	printf("%d\n", ans);
	return 0;
}