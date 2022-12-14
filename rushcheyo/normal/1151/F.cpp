#include <cstdio>
#include <cstring>
const int P = 1000000007;
int n, k, a[105], cnt;
struct matrix
{
	int data[105][105];
	int *operator[](int x) { return data[x]; }
	const int *operator[](int x) const { return data[x]; }
	matrix() { memset(data, 0, sizeof data); }
} ans, now;
matrix operator*(const matrix &a, const matrix &b)
{
	matrix res;
	for (int k = 0; k <= cnt; ++k)
		for (int i = 0; i <= cnt; ++i)
			if (a[i][k])
				for (int j = 0; j <= cnt; ++j)
					res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % P;
	return res;
}
int power(int a, int x)
{
	int ans = 1;
	for (; x; x >>= 1, a = 1LL * a * a % P)
		if (x & 1) ans = 1LL * ans * a % P;
	return ans;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), cnt += !a[i];
	int init = 0;
	for (int i = 1; i <= cnt; ++i) init += !a[i];
	int p = power(n * (n - 1) / 2, P - 2);
	for (int i = 0; i <= cnt; ++i)
	{
		int p1 = 1LL * i * ((n - cnt) - (cnt - i)) * p % P, p2 = 1LL * (cnt - i) * (cnt - i) * p % P, p3 = ((1 - p1 - p2) % P + P) % P;
		if (i)
			now[i][i - 1] = p1;
		if (i < cnt)
			now[i][i + 1] = p2;
		now[i][i] = p3;
		ans[i][i] = 1;
	}
	for (; k; k >>= 1, now = now * now)
		if (k & 1) ans = ans * now;
	printf("%d\n", ans[init][cnt]);
	return 0;
}