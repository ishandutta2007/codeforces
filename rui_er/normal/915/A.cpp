//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int n, k, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n, greater<int>());
	rep(i, 1, n) if(!(k % a[i])) return printf("%d\n", k/a[i])&0;
	return 0;
}