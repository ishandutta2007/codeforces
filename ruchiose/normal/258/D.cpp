// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, A[1010];
double p[1010][1010];

int main()
{
	scanf("%d%d", &N, &M);
	int i, j;
	fortodo(i, 1, N) scanf("%d", &A[i]);
	fortodo(i, 1, N)
		fortodo(j, 1, N)
			if (A[i] > A[j])
				p[i][j] = 1.0;
			else
				p[i][j] = 0.0;
	fortodo(i, 1, M)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			p[u][v] = p[v][u] = 0.5;
			fortodo(j, 1, N)
				if ((j != u) && (j != v))
					{
						p[j][u] = p[j][v] = (p[j][u] + p[j][v]) / 2;
						p[u][j] = p[v][j] = (p[u][j] + p[v][j]) / 2;
					}
		}
	double ret = 0;
	fortodo(i, 1, N)
		fortodo(j, i + 1, N)
			ret += p[i][j];
	printf("%.12f\n", ret);
}