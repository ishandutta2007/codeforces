#include <bits/stdc++.h>

using namespace std;

const int N = 300030;

struct lhy{
	int v, id;
}a[N];

int flag1[N], flag2[N];

inline int cmp(const lhy &a, const lhy &b)
{
	return a.v < b.v;
}

int main()
{
	int n, x1, x2;
	scanf("%d%d%d", &n, &x1, &x2);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i].v), a[i].id = i;
	sort(a + 1, a + 1 + n, cmp);
	for(int i = n; i; i--)
	{
		int nowk = (x2 - 1) / a[i].v + 1;
		if(n - i + 1 >= nowk)
		{
			if(flag1[i + nowk])
			{
				puts("Yes");
				int kk = (x1 - 1) / a[flag1[i + nowk]].v + 1;
				printf("%d %d\n", kk, nowk);
				for(int j = 1; j <= kk; j++)
					printf("%d ", a[flag1[i + nowk] + j - 1].id);
				puts("");
				for(int j = 1; j <= nowk; j++)
					printf("%d ", a[i + j - 1].id);
				puts("");
				return 0;
			}
			flag2[i] = i;
		}
		else flag2[i] = flag2[i + 1];
		nowk = (x1 - 1) / a[i].v + 1;
		if(n - i + 1 >= nowk)
		{
			if(flag2[i + nowk])
			{
				puts("Yes");
				int kk = (x2 - 1) / a[flag2[i + nowk]].v + 1;
				printf("%d %d\n", nowk, kk);
				for(int j = 1; j <= nowk; j++)
					printf("%d ", a[i + j - 1].id);
				puts("");
				for(int j = 1; j <= kk; j++)
					printf("%d ", a[flag2[i + nowk] + j - 1].id);
				puts("");
				return 0;
			}
			flag1[i] = i;
		}
		else flag1[i] = flag1[i + 1];
	}
	puts("No");
}