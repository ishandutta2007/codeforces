#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;


int a[200][200];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	if (n == 1 && m == 1)
	{
		printf("1\n");
		return 0;
	}

	bool sw = false;

	if (n < m)
	{
		swap(n, m);
		sw = true;
	}

	if ((m == 1 && n < 4) || (m == 2 && n == 2))
	{
		printf("-1");
		return 0;
	}

	if (n == 3 && m == 2)
	{
		a[0][0] = 5;
		a[0][1] = 3;
		a[1][0] = 1;
		a[1][1] = 6;
		a[2][0] = 4;
		a[2][1] = 2;
	}
	else
	if (n == 4 && m == 1)
	{
		a[0][0] = 3;
		a[1][0] = 1;
		a[2][0] = 4;
		a[3][0] = 2;
	}
	else
	{

		int s = n * m;
		int k1 = 0; 
		int k2 = (s + 1) / 2;

		while (s > 0)
		{
			a[k1 / m][(k1 % m)] = s;
			s--;
			k1++;
			a[k2 / m][(k2 % m)] = s;
			s--;
			k2++;
		}

	}

	if (!sw)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}



	return 0;
}