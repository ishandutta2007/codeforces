//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int x) {
	printf("+ %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
void give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	int L = 1, R = n;
	while(L + 1 < R) {
		int M = (L + R) >> 1;
		int diff = n - M % n;
		if(ask(diff) == (L + diff) / n) R = M;
		else L = M;
		L += diff; R += diff;
	}
	give(L);
	return 0;
}