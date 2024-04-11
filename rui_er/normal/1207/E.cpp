//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int L, int R, int x) {
	printf("?");
	rep(i, L, R) printf(" %d", i<<x);
	puts("");
	fflush(stdout);
	scanf("%d", &R);
	return R;
}
void give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
	int A = ask(1, 100, 0);
	int B = ask(1, 100, 7);
	give((A>>7<<7)|(B&127));
	return 0;
}