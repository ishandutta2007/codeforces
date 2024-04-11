//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int n, p[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int x, int y) {
	printf("?");
	rep(i, 1, n-1) printf(" %d", x);
	printf(" %d\n", y);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}
void give() {
	printf("!");
	rep(i, 1, n) printf(" %d", p[i]);
	puts("");
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	p[n] = n;
	rep(dt, 1, n-1) if(ask(1, 1+dt)) p[n] = n - dt;
	rep(i, 1, n) if(i != p[n]) p[ask(p[n], i)] = i;
	give();
	return 0;
}