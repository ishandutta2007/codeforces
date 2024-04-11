#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, U, E[N];

int check()
{
	for(int i = 1; i + 2 <= n; i++)
		if(E[i + 2] - E[i] <= U)return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &U);
	for(int i = 1; i <= n; i++)
		scanf("%d", &E[i]);
	if(check())
	{
		puts("-1");
		return 0;
	}
	int k = 1;
	long double ans = 0;
	for(int i = 1; i <= n; i++)
	{
		while(k < n && E[k + 1] - E[i] <= U)k++;
		if(k - i + 1 >= 3)ans = max(ans,(long double) 1. * (E[k] - E[i + 1]) / (E[k] - E[i]));
	}
	printf("%.10f\n", (double)ans);
}