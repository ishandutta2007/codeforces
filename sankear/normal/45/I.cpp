#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

int a[200];
int n;
int k = 0, p = 0, m = 0;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			k++;
		}
		if (a[i] > 0)
		{
			p++;
		}
		if (a[i] == 0)
		{
			m++;
		}
	}

	if (n == 1)
	{
		printf("%d", a[0]);
		return 0;
	}

	if (k == 1 && p == 0 && m > 0)
	{
			printf("0");
		return 0;
	}


	if (p == 0 && k == 0)
	{
		for (int i = 0; i < n; i++)
		{
			printf("0 ");
		}
		return 0;
	}

	if (k % 2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				printf("%d ", a[i]);
			}
		}
		return 0;
	}

	if (k % 2 != 0)
	{
		int j = 0;
		while (a[j] >= 0)
		{
			j++;
		}

		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0 && a[i] > a[j])
			{
				j = i;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0 && i != j)
			{
				printf("%d ", a[i]);
			}
		}
	}
	return 0;
}