//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], pre[N], suf[N], ans = 1; 

int main() {
	scanf("%d", &n); pre[1] = suf[n] = 1;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 2, n) {pre[i] = (a[i] > a[i-1]) * pre[i-1] + 1; ans = max(ans, pre[i-1]+1);}
	per(i, n-1, 1) {suf[i] = (a[i] < a[i+1]) * suf[i+1] + 1; ans = max(ans, suf[i+1]+1);}
	rep(i, 2, n-1) ans = max(ans, (a[i+1]-a[i-1]>1)*(pre[i-1]+suf[i+1]+1));
	printf("%d\n", ans);
	return 0;
}