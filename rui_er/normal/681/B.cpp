//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int n; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 0, n/1234567)
		rep(j, 0, (n-1234567*i)/123456)
			if((n - 1234567 * i - 123456 * j) % 1234 == 0)
				return puts("YES")&0;
	puts("NO");
	return 0;
}