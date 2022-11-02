#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 150;
const int Inf = 0x3f3f3f3f;

struct Edge
{
	int u, v, d;
	Edge() { }
	bool operator <(const Edge &rhs) const
	{
		return d < rhs.d;
	}
}edge[N];

typedef vector <bitset <N> > Matrix;
Matrix multiply(const Matrix &lhs, const Matrix &rhs)
{
	Matrix inv_rhs = rhs;
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < i; j ++)
		{
			//swap(inv_rhs[i][j], inv_rhs[j][i]);
			bool tmp = inv_rhs[i][j];
			inv_rhs[i][j] = inv_rhs[j][i];
			inv_rhs[j][i] = tmp;
		}
	Matrix ret = Matrix(N);
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			ret[i][j] = (lhs[i] & inv_rhs[j]).any();
	return ret;
}
Matrix qpow(const Matrix &m, int b)
{
	Matrix ret = m;
	Matrix tmp = m;
	b --;
	while(b > 0)
	{
		if(b & 1)
			ret = multiply(ret, tmp);
		tmp = multiply(tmp, tmp);
		b >>= 1;
	}
	return ret;
}

bitset <N> multiply(const Matrix& lhs, const bitset <N> &rhs)
{
	bitset <N> ret;
	for(int i = 0; i < N; i ++)
		ret[i] = (lhs[i] & rhs).any();
	return ret;
}

int solve(const bitset <N> mask, int n, int m)
{
	/*
	for(int i = 0; i < n; i ++)
		cout << mask[i] << ' ';
	cout << '\n';
	cout << m << '\n';
	*/
	static int dis[N];
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i < N; i ++)
		if(mask[i])
			dis[i] = 0;
	for(int t = 0; t < N; t ++)
		for(int i = 0; i < m; i ++)
			dis[edge[i].v] = min(dis[edge[i].u] + 1, dis[edge[i].v]);
	return dis[n - 1];
}

int main()
{
	ios :: sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].d;
		edge[i].u --;
		edge[i].v --;
	}
	sort(edge, edge + m);

	bitset <N> now;
	now[0] = 1;
	int ans = Inf;
	int last_time = 0;
	for(int i = 0; i < m; i ++)
	{
		if(edge[i].d != last_time)
		{
			Matrix step(N);
			for(int j = 0; j < i; j ++)
				step[edge[j].v][edge[j].u] = 1;
			now = multiply(qpow(step, edge[i].d - last_time), now);
			last_time = edge[i].d;
		}
		ans = min(ans, last_time + solve(now, n, i + 1));
	}
	if(ans == Inf)
		cout << "Impossible\n";
	else
		cout << ans << '\n';

	return 0;
}