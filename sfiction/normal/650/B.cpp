#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5E5 + 10;

int n;
int a, b, T;
char s[MAXN];
int pre[MAXN];

int main(){
	scanf("%d%d%d%d", &n, &a, &b, &T);
	scanf("%s", s);

	pre[0] = s[0] == 'w';
	int ans = pre[0] * b + 1 <= T;
	for (int i = 1; i < n; ++i){
		pre[i] = pre[i - 1] + (s[i] == 'w');
		if (i * a + pre[i] * b + i + 1 <= T)
			ans = i + 1;
	}
	pre[n] = pre[n - 1];

//	printf("%d %d\n", ans, pre[n - 1]);

	for (int j = n - 2, i = n - 1; i > 0; --i){
		int cost = 0;
		j = min(j, i - 1);
		for (; 0 <= j; --j){
			cost = (n - i + j + min(n - i, j)) * a + (pre[j] + pre[n] - pre[i - 1]) * b + n - i + j + 1;
//			printf("%d %d %d, %d %d\n", i, j, cost, pre[j], pre[n] - pre[i - 1]);
			if (cost <= T)
				break;
		}
		if (0 <= j)
			ans = max(ans, n - i + j + 1);
	}
	printf("%d\n", ans);

	return 0;
}