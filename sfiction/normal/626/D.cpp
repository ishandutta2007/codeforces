#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E3 + 10, MAXA = 5E3 + 10;

int n, a[MAXN];
int b[MAXA];
ll c[MAXA << 1];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			++b[a[i] - a[j]];
	int m = a[n - 1] - a[0];
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= m; ++j)
			c[i + j] += b[i] * b[j];
	double ans = 0;
	ll cnt = 0;
	for (int i = 0; i <= m; ++i){
		ans += b[i] * cnt;
		cnt += c[i];
	}
	double tot = n * (n - 1) / 2;
	printf("%.12f\n", ans / tot / tot / tot);
	return 0;
}