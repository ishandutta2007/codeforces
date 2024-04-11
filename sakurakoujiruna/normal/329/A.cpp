#include <iostream>
#include <cstdio>
using namespace std;

const int N = 111;

char c[N][N];
int cnt1[N];
int cnt2[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		scanf("%s", c[i] + 1);

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(c[i][j] == 'E')
			{
				cnt1[i] ++;
				cnt2[j] ++;
			}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(cnt1[i] == n && cnt2[j] == n)
			{
				cout << -1 << '\n';
				return 0;
			}

	for(int i = 1; i <= n; i ++)
		if(cnt1[i] == n)
		{
			for(int j = 1; j <= n; j ++)
				for(int i = 1; i <= n; i ++)
					if(c[i][j] == '.')
					{
						cout << i << ' ' << j << '\n';
						break;
					}
			return 0;
		}

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
			if(c[i][j] == '.')
			{
				cout << i << ' ' << j << '\n';
				break;
			}
	}
	return 0;
}