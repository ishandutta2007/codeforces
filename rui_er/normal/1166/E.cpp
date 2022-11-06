//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e4+5;

int m, n;
bitset<N> S[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &m, &n);
	rep(i, 1, m) {
		int k;
		scanf("%d", &k);
		rep(j, 1, k) {
			int x;
			scanf("%d", &x);
			S[i].set(x);
		}
	}
	rep(i, 1, m) {
		rep(j, i+1, m) {
			if(!(S[i] & S[j]).count()) return puts("impossible")&0;
		}
	}
	puts("possible");
	return 0;
}