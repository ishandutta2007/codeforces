#include <bits/stdc++.h>

using namespace std;

void solve()
{
	char s[5];
	scanf("%s", s);
	int ans = 0;
	ans += (s[0] - 'a') * 25;
	ans += (s[1] - 'a');
	if (s[1] > s[0])
		ans--;
	ans++;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}