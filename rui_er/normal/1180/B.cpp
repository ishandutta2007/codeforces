//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i] >= 0) a[i] = -a[i] - 1;
	}
	if(n & 1) {
		int mx = 1;
		rep(i, 2, n) if(a[i] < a[mx]) mx = i;
		a[mx] = -a[mx] - 1;
	}
	rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}