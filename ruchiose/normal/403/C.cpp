#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 2010;

int N;
int E[MAXN][MAXN], B[MAXN], S[MAXN], I[MAXN], S0, Cntpack;

void Visit(int x)
{
	S0++;
	B[x] = S[x] = S0;
	I[x] = 1;
	int i;
	fortodo(i, 1, N)
		if (E[x][i])
			if ((B[i]) && (I[i]))
				S[x] = min(S[x], B[i]);
			else
				if (!B[i])
					{
						Visit(i);
						S[x] = min(S[x], S[i]);
					}	
	if (B[x] == S[x]) Cntpack++;
}

int main()
{
	scanf("%d", &N);
	int i, j;
	fortodo(i, 1, N)
		fortodo(j, 1, N)
			scanf("%d", &E[i][j]);
	fortodo(i, 1, N)
		B[i] = S[i] = I[i] = 0;
	S0 = Cntpack = 0;
	Visit(1);
	if ((S0 == N) && (Cntpack == 1))
		printf("YES\n");
	else
		printf("NO\n");
}