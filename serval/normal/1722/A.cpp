#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 16;

int n;
char s[N];

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	if (n != 5)
	{
		printf("NO\n");
		return;
	}
	sort(s + 1, s + n + 1);
	if (strcmp(s + 1, "Timru") == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}