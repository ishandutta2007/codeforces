//By: Luogu@rui_er(122461)...
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, A, B = -1, a[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &A);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i] != A && buc[a[i]] < buc[A]) continue;
		++buc[a[i]];
	}
	rep(i, 1, N-5) {
		if(i != A && buc[i] >= buc[A]) {
			B = i;
			break;
		}
	}
	printf("%d\n", B);
	return 0;
}