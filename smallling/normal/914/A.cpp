#include <bits/stdc++.h>

using namespace std;

int n, a[1010];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int nowm = -1e6;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < 0)nowm = max(nowm, a[i]);
		else
		{
			int o = sqrt(a[i] + 1e-9);
			if(o * o != a[i])nowm = max(nowm, a[i]);
		}
	}
	printf("%d\n", nowm);
}