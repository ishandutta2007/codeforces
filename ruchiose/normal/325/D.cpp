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

int R, C, N;
int F[18000010];
int exi[3010][6010];

int Find(int x)
{
	return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

void Union(int x, int y)
{
	F[Find(x)] = Find(y);
}

bool Cnx(int x, int y)
{
	return Find(x) == Find(y);
}

#define B(r, c) ((r - 1) * C * 2 + (c - 1))

int decyc(int x)
{
	if (x == 0) return C * 2;
	if (x > C * 2) return 1;
	return x;
}

void Create(int r, int c)
{
	int dr, dc;
	fortodo(dr, -1, 1)
		fortodo(dc, -1, 1)
			if (exi[r + dr][decyc(c + dc)])
				Union(B(r, c), B(r + dr, decyc(c + dc)));
	exi[r][c] = true;
}

bool pseudoConnect(int r1, int c1, int r2, int c2)
{
	int dr1, dc1, dr2, dc2;
	fortodo(dr1, -1, 1)
		fortodo(dc1, -1, 1)
			if (exi[r1 + dr1][decyc(c1 + dc1)])
				fortodo(dr2, -1, 1)
					fortodo(dc2, -1, 1)
						if ((exi[r2 + dr2][decyc(c2 + dc2)]) && (Cnx(B(r1 + dr1, decyc(c1 + dc1)), B(r2 + dr2, decyc(c2 + dc2)))))
							return true;
	return false;
}

int main()
{
	scanf("%d%d%d", &R, &C, &N);
	int i, j, s = R * C * 2;
	fortodo(i, 0, s - 1) F[i] = i;
	fortodo(i, 0, R + 1)
		fortodo(j, 0, C * 2 + 1)
			exi[i][j] = false;
	int count = 0;
	fortodo(i, 1, N)
		{
			int r, c;
			scanf("%d%d", &r, &c);
			if ((!pseudoConnect(r, c, r, c + C)) && (C > 1))
				{
					count++;
					Create(r, c);
					Create(r, c + C);
				}
		}
	printf("%d\n", count);
}