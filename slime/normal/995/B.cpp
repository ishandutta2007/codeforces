#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 205
using namespace std;
int a[maxn]; 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 1; i <= 2 * n; i += 2)
	{
		for(int j = i + 1; j <= 2 * n; j++)
		{
			if(a[j] != a[i]) continue;
			ans += j - (i + 1);
			for(int k = j; k >= i + 1; k--)
				a[k] = a[k - 1];
		}
	}
	printf("%d\n", ans);
	return 0;
}