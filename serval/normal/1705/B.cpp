#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
long long ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 1;
	ans = 0;
	while (a[l] == 0 && l < n)
		l++;
	for (int i = l; i < n; i++)
		ans += max(a[i], 1);
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}