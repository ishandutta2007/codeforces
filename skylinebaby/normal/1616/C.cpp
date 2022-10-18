#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		int ans = n - 1;
		for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
		{
			int dx = j - i;
			int dy = a[j] - a[i];
			int g = __gcd(dx, dy);
			if(g < 0) g = -g;
			dx /= g;
			dy /= g;
			int f = a[i];
			int sum = 0;
			for(int k = i; k < n; k += dx, f += dy)
			{
				if(a[k] == f) sum++;
			} 
			ans = min(ans, n - sum);
		}
		printf("%d\n", ans);
	}	
	return 0;
}