//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n, now = 1;
vector<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	while(n > 3) {
		rep(i, 1, (n+1)>>1) ans.push_back(now);
		n >>= 1; now <<= 1;
	}
	rep(i, 1, n-1) ans.push_back(now);
	ans.push_back(now*n);
	for(int i : ans) printf("%d ", i);
	return 0;
}