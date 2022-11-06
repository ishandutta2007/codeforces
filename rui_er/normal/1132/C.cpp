//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 5e3+5;
 
int n, m, col[N], s[3][N], sum, ans;
pair<int, int> a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &a[i].first, &a[i].second);
	sort(a+1, a+1+m);
	rep(i, 1, m) {
		int l = a[i].first, r = a[i].second;
		rep(i, l, r) ++col[i];
	}
	rep(i, 1, n) if(col[i]) ++sum;
	rep(i, 1, n) if(col[i] == 1 || col[i] == 2) ++s[col[i]][i];
	rep(i, 1, n) rep(j, 1, 2) s[j][i] += s[j][i-1];
	ans = sum;
	rep(i, 1, m) rep(j, i+1, m) {
		int l = a[i].first, r = a[i].second;
		int L = a[j].first, R = a[j].second;
		int mL = min(l, L), mR = max(r, R);
		int nL = max(l, L), nR = min(r, R);
		int now = 0;
		if(nL <= nR) now = s[1][nL] - s[1][mL-1] + s[1][mR] - s[1][nR-1] + s[2][nR] - s[2][nL-1];
		else now = s[1][r] - s[1][l-1] + s[1][R] - s[1][L-1];
		chkmin(ans, now);
	}
	printf("%d\n", sum-ans);
	return 0;
}