#include <bits/stdc++.h>

using namespace std;

long long a[100010];

int main()
{
	int X, d;
	scanf("%d%d", &X, &d);
	long long t = 1;
	for(int i = 30; i; i--)
	{
		while(X >= (1 << i) - 1)
		{
			for(int j = 1; j <= i; j++)
				a[++*a] = t;
			t += d;
			X -= (1 << i) - 1;
		}
	}
	printf("%I64d\n", *a);
	for(int i = 1; i <= *a; i++)
		printf("%I64d ", a[i]);
}