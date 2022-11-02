#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>

using namespace std;

char s1[110000], s2[110000];
int n, g[200][200];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	gets(s1);
	gets(s2);
	scanf("%d\n", &n);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l1 != l2)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < 26; i ++)
		for (int j = 0; j < 26; j ++)
			g[i][j] = i != j ? 1000000000 : 0;
	for (int i = 1; i <= n; i ++)
	{
		char c1, c2;
		int d;
		scanf("%c %c %d\n", &c1, &c2, &d);
		g[c1 - 'a'][c2 - 'a'] = min(g[c1 - 'a'][c2 - 'a'], d);
	}

	for (int k = 0; k < 26; k ++)
		for (int i = 0; i < 26; i ++)
			for (int j = 0; j < 26; j ++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	bool good = true;
	long long res = 0;
	for (int i = 0; i < l1; i ++)
	{
		int best = 1000000000;
		for (int j = 0; j < 26; j ++)
			if (g[s1[i] - 'a'][j] + g[s2[i] - 'a'][j] < best)
				best = g[s1[i] - 'a'][j] + g[s2[i] - 'a'][j];
		if (best == 1000000000)
		{
			printf("-1\n");
			return 0;
		}
		res += (long long)(best);
	}

	cout << res << endl;
	for (int i = 0; i < l1; i ++)
	{
		int best = 1000000000;
		for (int j = 0; j < 26; j ++)
			if (g[s1[i] - 'a'][j] + g[s2[i] - 'a'][j] < best)
				best = g[s1[i] - 'a'][j] + g[s2[i] - 'a'][j];
		for (int j = 0; j < 26; j ++)
			if (g[s1[i] - 'a'][j] + g[s2[i] - 'a'][j] == best)
			{
				printf("%c", 'a' + j);
				break;
			}
	}
	printf("\n");
	return 0;
}