//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, tot;
vector<int> ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	if(m < n - 1) return puts("Impossible")&0;
	int ok = 0;
	rep(i, 1, n) {
		rep(j, i+1, n) {
			if(__gcd(i, j) == 1) {
				ans[i].push_back(j);
				++tot;
				if(tot == m) {ok = 1; break;}
			}
		}
		if(ok) break;
	}
	if(!ok) return puts("Impossible")&0;
	puts("Possible");
	rep(i, 1, n) {
		for(auto j : ans[i]) {
			printf("%d %d\n", i, j);
			--tot;
		}
		if(!tot) break;
	}
    return 0;
}