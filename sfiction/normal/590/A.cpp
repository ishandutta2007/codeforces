#include <cstdio>
#include <vector>

using namespace std;

#define st first
#define nd second

const int MAXN = 5E5 + 10;

int n;
int a[MAXN];

int m;
int c[MAXN][2];

int ans[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[0] = a[1];
	a[n + 1] = a[n];

	m = 0;
	for (int i = 0; i <= n; ++i)
		if (a[i] == a[i + 1]){
			c[m][0] = i;
			c[m][1] = a[i];
			++m;
		}

	ans[0] = a[0];
	ans[1] = a[1];
	int step = 0;
	for (int i = 1; i < m; ++i){
		ans[c[i][0]] = ans[c[i][0] + 1] = c[i][1];
		if (c[i - 1][1] == c[i][1]){
			for (int j = c[i - 1][0]; j < c[i][0]; ++j)
				ans[j] = c[i][1];
			step = max(step, c[i][0] - c[i - 1][0] >> 1);
		}
		else{
			int l = c[i - 1][0] + 2, r = c[i][0] - 1;
			int mid = l + r >> 1;
			for (int j = l; j <= mid; ++j)
				ans[j] = c[i - 1][1];
			for (int j = mid + 1; j <= r; ++j)
				ans[j] = c[i][1];

			step = max(step, r - mid);
		}
	}

	printf("%d\n", step);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], "\n "[i < n]);

	return 0;
}