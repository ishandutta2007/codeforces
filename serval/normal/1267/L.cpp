#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define fo(p, q, r) for(p = (q); p <= (r); ++p)
#define fow(p, q, r) for(p = (q); p >= (r); --p)
#define arclr(p, q) memset(p, (q), sizeof(p))
using namespace std;

char s[1000005];
char ans[1005][1005];
int endc[1005];

int main()
{
	int n, l, k;
	scanf("%d%d%d", &n, &l, &k);
	scanf("%s", s);
	sort(s, s + n * l);
	int tot = 0, fir = 1;
	for(int i = 0; i < l; ++i)
	{
		ans[fir][i] = s[tot++];
		endc[fir] = i + 1;
		int x = fir;
		for(int j = fir + 1; j <= k; ++j)
		{
			ans[j][i] = s[tot++];
			endc[j] = i + 1;
			if (ans[j][i] != ans [j - 1][i]) x = j;
		}
		fir = x;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = endc[i]; j < l; ++j)
			ans[i][j] = s[tot++];
		ans[i][l] = '\0';
		printf("%s\n", ans[i]);
	}
}