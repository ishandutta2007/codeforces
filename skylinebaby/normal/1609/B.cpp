#include<bits/stdc++.h>
using namespace std;
char a[123456];
int pos[123456];
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	cin >> a;
	int ans = 0;
	for(int i = 0; i + 2 < n; i++)
	{
		if(a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
		{
			ans ++;
			pos[i + 2] = 1;
		}
	}
	for(int i = 0; i < q; i++)
	{
		int x;
		char z;
		scanf("%d %c", &x, &z);
		x--;
		if(z == a[x])
		{
			printf("%d\n", ans);
			continue;
		}
		a[x] = z;
		if(pos[x] || pos[x + 1] || pos[x + 2]) 
		{
			pos[x] = 0;
			pos[x + 1] = 0;
			pos[x + 2] = 0;
			ans--;	
		}
		if(x + 2 < n && a[x] == 'a' && a[x + 1] == 'b' && a[x + 2] == 'c') 
		{
			pos[x + 2] = 1;
			ans++;
		}
		if(x + 1 < n && x - 1 >= 0 && a[x - 1] == 'a' && a[x] == 'b' && a[x + 1] == 'c')
		{
			pos[x + 1] = 1;
			ans++;
		 }
		if(x - 2 >= 0 && a[x - 2] == 'a' && a[x - 1] == 'b' && a[x] == 'c') 
		{
			pos[x] = 1;
			ans ++;
		}

		printf("%d\n", ans);
	}
	return 0;
}