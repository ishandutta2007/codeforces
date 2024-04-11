#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int n;
char s[N];
char t[N];

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int chk = 1;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'B')
			s[i] = 'G';
		if (t[i] == 'B')
			t[i] = 'G';
		chk &= s[i] == t[i];
	}
	if (chk)
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