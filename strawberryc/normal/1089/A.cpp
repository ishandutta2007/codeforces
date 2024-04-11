#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int M = 4, N = 205;

bool f[M][M][N][N];
int n, nxtx[M][M][N][N], nxty[M][M][N][N], ansx[N], ansy[N];

bool win(int p, int x, int y)
{
	int SCORE = p == 5 ? 15 : 25;
	if (x == SCORE) return 1;
	if (y == SCORE) return 0;
	return x > y;
}

int main()
{
	int i, j, k, h, l, a, b;
	f[0][0][0][0] = 1;
	For (i, 0, 3) For (j, 0, 3)
	{
		if ((!i && !j) || (i == 3 && j == 3)) continue;
		int SCORE = i + j == 5 ? 15 : 25;
		For (k, 0, 200) For (h, 0, 200)
		{
			if (k >= SCORE && i && j < 3)
			{
				For (l, 0, Min(h, SCORE - 2))
					if (f[i - 1][j][k - SCORE][h - l])
						f[i][j][k][h] = 1,
						nxtx[i][j][k][h] = SCORE,
						nxty[i][j][k][h] = l;
			}
			if (h >= SCORE && j && i < 3)
			{
				For (l, 0, Min(k, SCORE - 2))
					if (f[i][j - 1][k - l][h - SCORE])
						f[i][j][k][h] = 1,
						nxtx[i][j][k][h] = l,
						nxty[i][j][k][h] = SCORE;
			}
			if (f[i][j][k][h]) continue;
			if (i && j < 3)
			{
				For (l, SCORE + 1, Min(k, h + 2))
					if (f[i - 1][j][k - l][h - (l - 2)])
						f[i][j][k][h] = 1,
						nxtx[i][j][k][h] = l,
						nxty[i][j][k][h] = l - 2;
			}
			if (f[i][j][k][h]) continue;
			if (j && i < 3)
			{
				For (l, SCORE + 1, Min(h, k + 2))
					if (f[i][j - 1][k - (l - 2)][h - l])
						f[i][j][k][h] = 1,
						nxtx[i][j][k][h] = l - 2,
						nxty[i][j][k][h] = l;
			}
		}
	}
	n = read();
	while (n--)
	{
		a = read(); b = read();
		int ia = -10, ib = 10, tia, tib;
		For (i, 0, 3) For (j, 0, 3)
			if ((i == 3 || j == 3) && f[i][j][a][b] && i - j > ia - ib)
				ia = tia = i, ib = tib = j;
		if (ia == -10)
		{
			puts("Impossible"); continue;
		}
		int cnt = ia + ib;
		printf("%d:%d\n", ia, ib);
		while (cnt--)
		{
			int tx = nxtx[ia][ib][a][b], ty = nxty[ia][ib][a][b];
			if (win(cnt + 1, tx, ty)) ia--;
			else ib--;
			ansx[cnt + 1] = tx; ansy[cnt + 1] = ty;
			a -= tx; b -= ty;
		}
		For (i, 1, tia + tib)
			printf("%d:%d ", ansx[i], ansy[i]);
		printf("\n");
	}
	return 0;
}