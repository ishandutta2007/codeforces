#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E6 + 10;

int n, k;
int v[MAXN], c[MAXN];
int f[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	for (int i = n - 1; i >= 0; --i)
		f[i] = min(max(f[i + 1], v[i] * 100), c[i]);
	sort(f, f + n);
	double ans = 0, mul = 1.0;
	for (int i = 0; i <= n - k; ++i){
		ans += f[i] * (mul /= (n - i));
		mul *= n - i - k;
	}
	printf("%.20f\n", ans * k);
	return 0;
}