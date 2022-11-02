#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 400040;

int ggg[M], tt[M], f[M], Rank[M], t[M], sa[M];
int q[M], ll[M], last[M], tot, l, s, m, n;
char c[M];
int len[N], nn, st[N], ans, height[M], L, R;
int A[N], K[N], LL;
int SQ, B[N];

void Sort(int x)
{
	if(x <= SQ)sort(A + 1, A + 1 + x);
	else
	{
		for(int i = 0; i <= SQ; i++)
			f[i] = 0;
		for(int i = 1; i <= x; i++)
			f[(A[i] % SQ) + 1]++;
		for(int i = 1; i <= SQ; i++)
			f[i] += f[i - 1];
		for(int i = 1; i <= x; i++)
			B[++f[A[i] % SQ]] = A[i];
		for(int i = 0; i <= SQ; i++)
			f[i] = 0;
		for(int i = 1; i <= x; i++)
			f[(B[i] / SQ) + 1]++;
		for(int i = 1; i <= SQ; i++)
			f[i] += f[i - 1];
		for(int i = 1; i <= x; i++)
			A[++f[B[i] / SQ]] = B[i];
	}
}

inline int work(int x, int y, int z)
{
	if(y > x)return -1;
	Sort(x);
	int ans = n + 1;
	for(int i = y; i <= x; i++)
		ans = min(ans, A[i] - A[i - y + 1] + z);
	return ans;
}

int main()
{
	scanf("%s", c + 1);
	n = strlen(c + 1);
	LL = n;
	c[++n] = '&';
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &K[i]);
		scanf("%s", c + n + 1);
		st[i] = n + 1;
		len[i] = strlen(c + n + 1);
		n = strlen(c + 1);
		c[++n] = '&';
	}
	for(int i = 1; i <= n; i++)
	{
		Rank[i] = int(c[i]);
		ggg[Rank[i]]++;
	}
	for(int i = 1; i <= M - 5; i++)
		f[i] = f[i - 1] + ggg[i], ggg[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		t[Rank[i]]++;
		sa[f[Rank[i] - 1] + t[Rank[i]]] = i;
	}
	for(int tot = 0, j = 1; j < n; j *= 2, tot = 0)
	{
		for(int i = n; i > n - j; i--)
			q[++tot] = i, tt[i] = 0;
		for(int i = 1; i <= n; i++)
			if(sa[i] - j > 0)
			{
				q[++tot] = sa[i] - j;
				tt[q[tot]] = Rank[sa[i]];
			}
		for(int i = 1; i <= n; i++)
			ggg[Rank[q[i]]]++;
		for(int i = 1; i <= M - 5; i++)
			f[i] = f[i - 1] + ggg[i], ggg[i] = 0, t[i] = ll[i] = 0, last[i] = -1;
		for(int i = 1; i <= tot; i++)
		{
			int yy = Rank[q[i]];
			if(last[yy] < tt[q[i]])ll[yy]++;
			Rank[q[i]] = f[yy - 1] + ll[yy];
			t[yy]++;
			sa[f[yy - 1] + t[yy]] = q[i];
			last[yy] = tt[q[i]];
		}
	}
	int k=0;
	for(int i = 1; i <= n; i++)
	{
		k -= (k > 0);
		int j = sa[Rank[i] - 1], l1 = i + k, l2 = j + k;
		while(l1 <= n && l2 <= n)
		{
			if(c[l1] == c[l2])
			{
				l1++;l2++;k++;
			}
			else break;
		}
		height[Rank[i]] = k;
	}
	SQ = int(sqrt(100000)) + 1;
	for(int i = 1; i <= m; i++)
	{
		L = Rank[st[i]] - 1;
		while(L && height[L + 1] >= len[i])L--;
		R = Rank[st[i]] + 1;
		while(R <= n && height[R] >= len[i])R++;
		L++, R--;
		tot = 0;
		for(int j = L; j <= R; j++)
			if(sa[j] <= LL)A[++tot] = sa[j];
		printf("%d\n", work(tot, K[i], len[i]));
	}
}