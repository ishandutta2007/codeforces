//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 32768;

int n, x, pw[16];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	pw[0] = 1;
	rep(i, 1, 15) pw[i] = 2 * pw[i-1] % N;
	for(scanf("%d", &n);n;n--) {
		scanf("%d", &x);
		int ans = N;
		rep(i, 0, 15) {
			rep(j, 0, 15) {
				if(!((x + j) % N * pw[i] % N)) {
					chkmin(ans, i + j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}