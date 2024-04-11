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
	while(true) {
		if(!n) return puts("YES")&0;
		else if(n % 10 == 1) n /= 10;
		else if(n % 100 == 14) n /= 100;
		else if(n % 1000 == 144) n /= 1000;
		else return puts("NO")&0;
	}
	return 0;
}