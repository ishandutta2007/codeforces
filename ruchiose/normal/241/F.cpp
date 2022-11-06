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

int N, M, K;
int C[110][110], PR[110][110], PC[110][110];
int X[26], Y[26];

int Dist(int x, int y, int xp, int yp)
{
	if (x == xp)
		if (y <= yp)
			return PR[x][yp - 1] - PR[x][y - 1];
		else
			return PR[x][y] - PR[x][yp];
	else
		if (x <= xp)
			return PC[xp - 1][y] - PC[x - 1][y];
		else
			return PC[x][y] - PC[xp][y];
}

void Route(int x, int y, int xp, int yp)
{
	if (K >= Dist(x, y, xp, yp))
		{
			K -= Dist(x, y, xp, yp);
			return;
		}
	int dx = (x == xp) ? 0 : ((x < xp) ? 1 : -1);
	int dy = (y == yp) ? 0 : ((y < yp) ? 1 : -1);
	while (K >= C[x][y])
		{
			K -= C[x][y];
			x += dx;
			y += dy;
		}
	printf("%d %d\n", x, y);
	exit(0);
}

char S[100010];
int sx, sy, ex, ey;

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	int i, j;
	fortodo(i, 0, 25) X[i] = Y[i] = 0;
	fortodo(i, 1, N)
		{
			char ch[110];
			scanf("%s", ch + 1);
			fortodo(j, 1, M)
				if (ch[j] == '#')
					C[i][j] = 0;
				else
					if ((ch[j] >= '0') && (ch[j] <= '9'))
						C[i][j] = ch[j] - '0';
					else
						{
							C[i][j] = 1;
							X[ch[j] - 'a'] = i;
							Y[ch[j] - 'a'] = j;
						}
		}
	fortodo(i, 1, N)
		{
			PR[i][0] = 0;
			fortodo(j, 1, M)
				PR[i][j] = PR[i][j - 1] + C[i][j];
		}
	fortodo(i, 1, M)
		{
			PC[0][i] = 0;
			fortodo(j, 1, N)
				PC[j][i] = PC[j - 1][i] + C[j][i];
		}
	scanf("%d%d%s%d%d", &sx, &sy, S + 1, &ex, &ey);
	Route(sx, sy, X[S[1] - 'a'], Y[S[1] - 'a']);
	int s0 = strlen(S + 1);
	fortodo(i, 2, s0)
		Route(X[S[i - 1] - 'a'], Y[S[i - 1] - 'a'], X[S[i] - 'a'], Y[S[i] - 'a']);
	Route(X[S[s0] - 'a'], Y[S[s0] - 'a'], ex, ey);
	printf("%d %d\n", ex, ey);
}