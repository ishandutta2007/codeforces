#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXS = 5010;
const int MAXN = 10010;

char S1[MAXS], S2[MAXS];
int C[MAXN], N1, N2, N, i, j;

int Step, SA[MAXN], RK[MAXN], NK[MAXN], head[MAXN], nx[MAXN], Hei[MAXN];

bool cmp_sapr(int a, int b)
{
	return C[a] < C[b];
}

int Rank(int x)
{
	return (x <= N) ? RK[x] : 0;
}

bool SAE(int a, int b)
{
	return ((RK[a] == RK[b]) && (RK[a + Step] == RK[b + Step]));
}

void regi(int u, int g)
{
	nx[u] = head[g];
	head[g] = u;
}

void GetSA()
{
	int i, j;
	fortodo(i, 1, N) SA[i] = i;
	sort(SA + 1, SA + N + 1, cmp_sapr);
	RK[SA[1]] = RK[0] = 1;
	fortodo(i, 2, N)
		{
			if (C[SA[i]] != C[SA[RK[0]]]) RK[0] = i;
			RK[SA[i]] = RK[0];
		}
	for (Step = 1; Step < N; Step <<= 1)
		{
			fortodo(i, 0, N) head[i] = 0;
			fortodo(i, 1, N) regi(i, Rank(i + Step));
			SA[0] = 0;
			for (i = N; i >= 0; i--)
				for (j = head[i]; j; j = nx[j])
					SA[++SA[0]] = j;
			fortodo(i, 1, N) head[i] = 0;
			fortodo(i, 1, N) regi(SA[i], Rank(SA[i]));
			SA[0] = 0;
			fortodo(i, 1, N)
				for (j = head[i]; j; j = nx[j])
					SA[++SA[0]] = j;
			NK[SA[1]] = NK[0] = 1;
			fortodo(i, 2, N)
				{
					if (!SAE(SA[i], SA[NK[0]])) NK[0] = i;
					NK[SA[i]] = NK[0];
				}
			fortodo(i, 1, N) RK[i] = NK[i];
		}
	#define H(x) Hei[RK[x]]
	#define P(x) SA[RK[x] - 1]
	H(0) = 0;
	fortodo(i, 1, N)
		{
			H(i) = max(0, H(i - 1) - 1);
			while ((i + H(i) <= N) && (P(i) + H(i) <= N) && (C[i + H(i)] == C[P(i) + H(i)]))
				H(i)++;
		}
}

bool chk(int h)
{
	int c[2];
	c[0] = c[1] = 0;
	int i;
	fortodo(i, 1, N)
		{
			if ((SA[i] >= 1) && (SA[i] <= N1)) c[0]++;
			if ((SA[i] > N1 + 1) && (SA[i] < N)) c[1]++;
			if ((i == N) || (Hei[i + 1] < h))
				{
					if ((c[0] == 1) && (c[1] == 1)) return true;
					c[0] = c[1] = 0;
				}
		}
	return false;
}

int main()
{
	scanf("%s%s", S1 + 1, S2 + 1);
	N1 = strlen(S1 + 1);
	N2 = strlen(S2 + 1);
	N = N1 + N2 + 2;
	fortodo(i, 1, N1) C[i] = S1[i] - 'a';
	fortodo(i, 1, N2) C[N1 + 1 + i] = S2[i] - 'a';
	C[N1 + 1] = -1;
	C[N] = -2;
	GetSA();
	int MinN = min(N1, N2);
	fortodo(i, 1, MinN)
		if (chk(i))
			{
				printf("%d\n", i);
				return 0;
			}
	printf("-1\n");
}