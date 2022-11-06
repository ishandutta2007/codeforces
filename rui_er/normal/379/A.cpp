//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int n, k, ans, qwq; 

int main() {
	scanf("%d%d", &n, &k);
	ans = n;
	while(n / k) {
		ans += (qwq = n / k);
		(n %= k) += qwq;
	}
	printf("%d\n", ans);
	return 0;
}