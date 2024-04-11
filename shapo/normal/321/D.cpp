#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef vector < int > vi;
typedef vector < vi > vvi;

const int INF = 0x3f3f3f3f;

#define maxn 40

int a[maxn][maxn];
int mult[maxn][maxn];
int ans;
int n, x;

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifndef _DEBUG
	ios_base::sync_with_stdio(false);
	cin >> n;
#else
	if (!(cin >> n))
	{
		return false;
	}
#endif
	ans = -INF;
	x = (n + 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
#ifdef _DEBUG
	return true;
#endif
}

inline int in_cell(const int x, const int y)
{
	return a[x][y] * mult[x][y];
}

int sum_in_col(const int col_id)
{
	int res = 0;
	for (int i = 1; i < x; ++i)
	{
		mult[i][col_id] = 1;
		mult[i + x][col_id] = mult[i][col_id] * mult[x][col_id];
		mult[i][col_id + x] = mult[i][col_id] * mult[i][x];
		mult[i + x][col_id + x] = mult[i + x][col_id] * mult[i + x][x];
		int cur_sum = in_cell(i, col_id) + in_cell(i + x, col_id) +
			in_cell(i, col_id + x) + in_cell(i + x, col_id + x);
		res += abs(cur_sum);
	}
	res += in_cell(x, col_id) + in_cell(x, col_id + x);
	return res;
}

void process()
{
	int res = 0;
	for (int i = 1; i < x; ++i)
	{
		int cur_sum = -INF;
		mult[x][i] = 1;
		mult[x][i + x] = mult[x][x];
		cur_sum = max(cur_sum, sum_in_col(i));
		mult[x][i] = -1;
		mult[x][i + x] = -mult[x][x];
		cur_sum = max(cur_sum, sum_in_col(i));
		res += cur_sum;
	}
	for (int i = 1; i <= n; ++i)
	{
		res += in_cell(i, x);
	}
	ans = max(ans, res);
}

void calc()
{
	for (int i = 0; i < (1 << x); ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			mult[j + 1][x] = ((i & (1 << j)) == 0) ? 1 : -1;
		}
		for (int j = 1; j < x; ++j)
		{
			mult[j + x][x] = mult[j][x] * mult[x][x];
		}
		process();
	}
	cout << ans << endline;
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {
#else
	input_data();
#endif
	calc();
#ifdef _DEBUG
	}
#endif
	return 0;
}