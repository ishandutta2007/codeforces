//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, m, k, a[N][N], ans, cnt;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
	rep(j, 1, m) {
		int now = 0, flp = 0, sum = 0, qwq = 0, pos = 0;
		rep(i, 1, n) {
			if(a[i][j]) {
				pos = i;
				break;
			}
		}
		if(!pos) continue;
		rep(i, pos, pos+k-1) sum += a[i][j];
		chkmax(now, sum);
		rep(i, pos+1, n) {
			qwq += a[i-1][j];
			sum -= a[i-1][j];
			if(i + k - 1 <= n) sum += a[i+k-1][j];
			if(a[i][j]) {
				if(sum > now) {
					now = sum;
					flp = qwq;
				}
			}
		}
		ans += now;
		cnt += flp;
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}