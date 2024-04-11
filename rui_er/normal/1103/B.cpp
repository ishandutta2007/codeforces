//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int inf = 1e9;

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char s[10];
	scanf("%s", s);
	return s[0] == 'x';
}
bool give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	char s[10];
	scanf("%s", s);
	return s[0] == 's';
}

int main() {
	scanf("%*s");
	int ans = 0;
	do {
		int L = 0, R = 1;
		while(true) {
			if(ask(L, R)) break;
			else {
				L = R;
				R <<= 1;
			}
		}
		while(L + 1 < R) {
			int M = (L + R) >> 1;
			if(ask(M, L)) L = M;
			else R = M;
		}
		ans = L + 1;
	}while(give(ans));
	return 0;
}