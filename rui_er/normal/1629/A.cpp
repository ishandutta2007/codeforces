//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105; 

int T, n, k;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Software {
	int a, b;
	Software(int a=0, int b=0) : a(a), b(b) {}
	~Software() {}
	friend bool operator < (const Software& a, const Software& b) {
		return a.a < b.a;
	}
}a[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d", &a[i].a);
		rep(i, 1, n) scanf("%d", &a[i].b);
		sort(a+1, a+1+n);
		rep(i, 1, n) {
			if(k < a[i].a) break;
			k += a[i].b;
		}
		printf("%d\n", k);
	} 
	return 0;
}