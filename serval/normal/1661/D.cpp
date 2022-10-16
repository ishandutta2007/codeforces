#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

int n, k;
long long a[N], b[N], s[N];
long long del, sum;
long long ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	for (int i = n; i; i--)
	{
		int curk = min(i, k);
		a[i] = b[i] - del;
		if (a[i] > 0)
			s[i] = (a[i] + curk - 1) / curk;
		ans += s[i];
		sum += s[i];
		del += s[i] * curk;
		if (i + k <= n)
			sum -= s[i + k];
		del -= sum;
	}
	printf("%lld\n", ans);
	return 0;
}