#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int cnt[1010];
int a[1010],N;
char ans[1010];
vector<int>v[1010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (int i=1;i<=100;i++)
		v[cnt[i]].push_back(i);
	if (v[1].size() % 2 == 0)
	{
		puts("YES");
		int done = 0;
		for (int i=1;i<=N;i++)
		if (cnt[a[i]] == 1)
		{
			if (++done <= v[1].size() / 2)
			{
				putchar('A');
			}
			else
			{
				putchar('B');
			}
		}
		else
		{
			putchar('A');
		}
		return 0;
	}
	int first = 0;
	for (int i=3;i<=100;i++) 
	if (v[i].size() > 0) first = i;
	if (first == 0)
	{
		puts("NO");	
		return 0;
	} 
	puts("YES");
	int done = 0, done2 = 0;
	for (int i=1;i<=N;i++)
	if (cnt[a[i]] == 1)
	{
		if (++done <= v[1].size() / 2)
		{
			putchar('A');
		}
		else
		{
			putchar('B');
		}
	}
	else if (a[i] == v[first][0])
	{
		if (++done2 == 1)
			putchar('A');
		else
			putchar('B');
	}
	else
	{
		putchar('A');
	}
}