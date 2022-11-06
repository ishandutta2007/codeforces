//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 505; 

int n, m, a[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
int lcm(int x, int y) {return x / __gcd(x, y) * y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) {
		scanf("%d", &a[i][j]);
		rep(_, 1, 2) a[i][j] *= a[i][j];
	}
	int k = 1;
	rep(i, 2, 16) k = lcm(k, i);
//	printf("%d\n", k);
	rep(i, 1, n) rep(j, 1, m) printf("%d%c", ((i+j)&1)?k:k-a[i][j], " \n"[j==m]);
	return 0;
}