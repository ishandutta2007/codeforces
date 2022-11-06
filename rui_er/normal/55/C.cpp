//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n, m, k;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int win = 0;
	rep(i, 1, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		int dis = min({x-1, y-1, n-x, m-y});
		win |= dis <= 4;
	}
	puts(win?"YES":"NO");
	return 0;
}