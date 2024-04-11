#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int cnt = 1;
	for(int i = n - 1; i; i--)
	{
		if(a[i] == a[i + 1])cnt++;
		else
		{
			if(cnt % 2 == 1)
			{
				puts("Conan");
				return 0;
			}
			cnt = 1;
		}
	}
	if(cnt % 2 == 1)puts("Conan");
	else puts("Agasa");
}