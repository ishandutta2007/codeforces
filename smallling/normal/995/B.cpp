#include <bits/stdc++.h>

using namespace std;

int a[110];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= 2 * n; i++)
		for(int j = i + 1; j <= 2 * n; j++)
			if(a[i] == a[j])
			{
				ans += j - i - 1;
				for(int k = j; k > i; k--)
					a[k] = a[k - 1];
				break;
			}
	printf("%d\n", ans);
}