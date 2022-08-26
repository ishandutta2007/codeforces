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
const int DX[] = { 1,  0,  0, -1 };
const int DY[] = { 0, -1,  1,  0 };
const char DC[] = {'D', 'L', 'R', 'U'};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 1111;

int n, m, k;
char f[N][N];
int rx, ry;
int d[N][N];

bool inField(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && f[x][y] != '*';
}

int main()
{
    ios::sync_with_stdio(false);
	scanf("%d%d%d", &n, &m, &k);
	if (k % 2 != 0)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", f[i]);
		for (int j = 0; j < m; ++j)
			if (f[i][j] == 'X')
			{
				rx = i;
				ry = j;
			}
	}

	memset(d, 0x3f, sizeof(d));
	vector < ipair > q;
	q.emplace_back(rx, ry);
	d[rx][ry] = 0;
	for (int i = 0; i < sz(q); ++i)
	{
		int x = q[i].X, y = q[i].Y;
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + DX[dir];
			int ny = y + DY[dir];
			if (!inField(nx, ny) || d[nx][ny] < IINF)
				continue;
			d[nx][ny] = d[x][y] + 1;
			q.emplace_back(nx, ny);
		}
	}

	string s;
	int x = rx, y = ry;
	for (int i = 0; i < k; ++i)
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + DX[dir];
			int ny = y + DY[dir];
			if (inField(nx, ny) && d[nx][ny] <= (k - i - 1))
			{
				x = nx;
				y = ny;
				s += DC[dir];
				break;
			}
		}
	if (sz(s) != k)
		s = "IMPOSSIBLE";
	cout << s << "\n";

    return 0;
}