#include <cstdio>

const int MAXN = 1E5 + 10;

int n;
int a[MAXN];

int main(){
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		cnt += a[i];
	}

	int low = cnt / n, high = (cnt + n - 1) / n;
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i){
		ans1 += a[i] < low ? low - a[i] : 0;
		ans2 += high < a[i] ? a[i] - high : 0;
	}
	printf("%d\n", ans1 < ans2 ? ans2 : ans1);
	return 0;
}