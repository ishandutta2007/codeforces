//LG rui_er 
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 205; 

int T, n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		n <<= 1;
		int odd = 0, even = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			(a[i] & 1) ? (++odd) : (++even);
		}
		if(odd == even) puts("Yes");
		else puts("No");
	}
	return 0;
}