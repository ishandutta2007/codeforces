/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 550B
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20;
const int INF = 0x7fffffff;

int n, l, r, x;
int c[MAXN];

int ans;

void DFS(int depth, int cnt, int a, int b){
	if (depth >= n){
		ans += l <= cnt && cnt <= r && b - a >= x;
		return;
	}

	DFS(depth + 1, cnt, a, b);
	DFS(depth + 1, cnt + c[depth], min(a, c[depth]), max(b, c[depth]));
}

int main(){
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	ans = 0;
	DFS(0, 0, INF, 0);
	printf("%d\n", ans);

	return 0;
}