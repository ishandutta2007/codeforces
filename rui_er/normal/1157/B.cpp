//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int n, a[N], b[10];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%1d", &a[i]);
	rep(i, 1, 9) scanf("%d", &b[i]);
	rep(i, 1, n) {
		if(b[a[i]] > a[i]) {
			rep(j, i, n) {
				if(b[a[j]] >= a[j]) a[j] = b[a[j]];
				else break;
			}
			break;
		}
	}
	rep(i, 1, n) printf("%d", a[i]);
	return 0;
}