#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int fa[N], cnt[N], sum[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		cnt[fa[i]]++;
	}
	for(int i = 2; i <= n; i++)
		if(!cnt[i])sum[fa[i]]++;
	for(int i = 1; i <= n; i++)
		if(cnt[i] && sum[i] < 3)
		{
			puts("No");
			return 0;
		}
	puts("Yes");
}