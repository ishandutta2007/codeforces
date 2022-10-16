#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n;
bool vis[255];
char s[N];

int solve()
{
	scanf("%d", &n);
	int ans = n;
	memset(vis, 0, sizeof(vis));
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		if (!vis[s[i]])
		{
			vis[s[i]] = 1;
			ans++;
		}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		printf("%d\n", solve());
	return 0;
}