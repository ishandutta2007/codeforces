#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 1024;
const int D = 10;

int n, m;
int a[N][N];
int s[N][N];
int d[N][N];
short st[D][D][N][N];
int stm[N];

int getMax(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2)
		return 0;
	int d1 = stm[x2-x1+1];
	int d2 = stm[y2-y1+1];
	return max(max(st[d1][d2][x1][y1], st[d1][d2][x2-(1<<d1)+1][y2-(1<<d2)+1]),
		max(st[d1][d2][x1][y2-(1<<d2)+1], st[d1][d2][x2-(1<<d1)+1][y1]));
}

int main()
{
    ios::sync_with_stdio(false);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
			s[i+1][j+1] = a[i][j] + s[i][j+1] + s[i+1][j] - s[i][j];
		}
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			if (a[i][j] != 0)
			{
				int k;
				for (k = d[i+1][j+1] + 1; k*k != s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j]; --k);
				d[i][j] = k;
			}
	
	for (int di = 0; di < D; ++di)
	{
		if (di == 0)
		{
			for (int i = 0; i + (1 << di) <= n; ++i)
				for (int j = 0; j < m; ++j)
					st[0][0][i][j] = d[i][j];
			for (int dj = 1; dj < D; ++dj)
				for (int i = 0; i + (1 << di) <= n; ++i)
					for (int j = 0; j + (1 << dj) <= m; ++j)
						st[di][dj][i][j] = max(st[di][dj-1][i][j], st[di][dj-1][i][j+(1<<(dj-1))]);
		}
		else
			for (int dj = 0; dj < D; ++dj)
				for (int i = 0; i + (1 << di) <= n; ++i)
					for (int j = 0; j + (1 << dj) <= m; ++j)
						st[di][dj][i][j] = max(st[di-1][dj][i][j], st[di-1][dj][i+(1<<(di-1))][j]);
	}
	for (int i = 1; i < N; ++i)
	{
		for (stm[i] = stm[i-1]; (1 << stm[i]) <= i; ++stm[i]);
		--stm[i];
	}

	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1; --y1; --x2; --y2;
		int al = 0, ar = min(x2-x1+1, y2-y1+1);
		while (al < ar)
		{
			int mid = (al + ar + 1) / 2;
			if (getMax(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
				al = mid;
			else
				ar = mid - 1;
		}
		cout << al << "\n";
	}

    return 0;
}