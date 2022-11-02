#include <iostream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

char s[110][110];
int n, m;
char c;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool val(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool have[26];

int main()
{
	scanf("%d %d %c\n", &n, &m, &c);
	for (int i = 0; i < n; i ++)
		gets(s[i]);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] == c)
				for (int k = 0; k < 4; k ++)
				{
					int a = i + dx[k], b = j + dy[k];
					if (val(a, b) && s[a][b] >= 'A' && s[a][b] <= 'Z') have[s[a][b] - 'A'] = true;
				}

	int res = 0;
	for (int i = 0; i < 26; i ++)
		if (i + 'A' != c && have[i]) res ++;
	printf("%d\n", res);
	return 0;
}