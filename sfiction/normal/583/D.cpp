#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1E2 + 10;

int n, T;
int a[MAXN];
int f[MAXN << 1][MAXN];
int g[MAXN << 1][MAXN];

template<typename T>
void solve(int m, int a[], int (&f)[MAXN << 1][MAXN], T op){
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j){
			for (int k = 1; k < j; ++k)
				if (op(a[k], a[j]))
					f[i][j] = max(f[i][j], f[i][k]);
			for (int k = j; k <= n; ++k)
				if (op(a[k], a[j]))
					f[i][j] = max(f[i][j], f[i - 1][k]);
			++f[i][j];
		}
}

int main(){
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = 0;
	if (T <= 2 * n){
		solve(T, a, f, less_equal<int>());
		for (int i = 1; i <= n; ++i)
			ans = max(ans, f[T][i]);
	}
	else{
		solve(n, a, f, less_equal<int>());
		reverse(a + 1, a + n + 1);
		solve(n, a, g, greater_equal<int>());
		for (int i = 1; i <= n; ++i){
			int t = 0, t1 = 0, t2 = 0;
			for (int j = 1; j <= n; ++j)
				if (a[i] == a[j]){
					++t;
					t1 = max(t1, f[n][n - j + 1]);
					t2 = max(t2, g[n][j]);
				}
			t = t * (T - n * 2) + t1 + t2;
			ans = max(ans, t);
		}
	}
	printf("%d\n", ans);
	return 0;
}