#include <cstdio>

using namespace std;

const int N = 5e5 + 5;

int n, k;
char s[N];
int p[N];
int ans;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	ans = 0;
	for (int i = 2, j = 0; i <= n; i++)
	{
		if (s[i] < s[j + 1])
			ans = i;
		while (j && s[i] < s[j + 1])
			j = p[j];
		if (s[i] > s[j + 1])
		{
			if (ans == 0)
				ans = i - 1;
			break;
		}
		if (s[i] == s[j + 1])
			j++;
		p[i] = j;
	}
	if (ans == 0)
		ans = n;
	for (int x = 1; x <= k; x++)
		printf("%c", s[(x - 1) % ans + 1]);
	printf("\n");
	return 0;
}