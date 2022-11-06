//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n, m, w[45], a[2][N], tot1, tot2, ans;
void dfs(int u, int s, int end, int tp, int &tot) {
	if(u == end) return a[tp][++tot] = s, a[tp][++tot] = (s + w[u]) % m, void();
	dfs(u+1, s, end, tp, tot); dfs(u+1, (s+w[u])%m, end, tp, tot);
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &w[i]);
	if(n == 1) return printf("%d\n", w[1]%m), 0;
	int mid = (n >> 1);
	dfs(1, 0, mid, 0, tot1);
	dfs(mid+1, 0, n, 1, tot2);
	sort(&a[0][1], &a[0][tot1+1]); sort(&a[1][1], &a[1][tot2+1]);
	int u = 0, v = tot2;
	while(u <= tot1) {
		while(a[0][u] + a[1][v] >= m) --v;
		ans = max(ans, a[0][u++]+a[1][v]);
	}
	ans = max(ans, (a[0][tot1]+a[1][tot2])%m);
	printf("%d\n", ans);
	return 0;
}