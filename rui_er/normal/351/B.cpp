//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e3+5, K = 3e3;

int n, a[N], c[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int lowbit(int x) {return x & (-x);}
void add(int x) {for(;x<=K;x+=lowbit(x)) ++c[x];}
int ask(int x) {int k=0; for(;x;x-=lowbit(x)) k+=c[x]; return k;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	per(i, n, 1) {
		ans += ask(a[i]-1);
		add(a[i]);
	}
	if(ans & 1) printf("%d\n", (ans<<1)-1);
	else printf("%d\n", ans<<1);
	return 0;
}