//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int a, b, x, y; 
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d%d", &a, &b, &x, &y);
	int g = __gcd(x, y);
	x /= g; y /= g;
	int k = min(a/x, b/y);
	x *= k; y *= k;
	printf("%d %d\n", x, y);
	return 0;
}