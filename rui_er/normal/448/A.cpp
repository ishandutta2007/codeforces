//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int n, A, B, nd;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	rep(i, 1, 3) {
		int x;
		scanf("%d", &x);
		A += x;
	}
	rep(i, 1, 3) {
		int x;
		scanf("%d", &x);
		B += x;
	}
	nd = (A + 4) / 5 + (B + 9) / 10;
	scanf("%d", &n);
	puts(nd<=n?"YES":"NO");
	return 0;
}