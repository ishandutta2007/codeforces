#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 300011;
typedef long double doublel;
const doublel Pi = 4 * atanl(1);

struct Matrix
{
	int n, m;
	doublel d[3][3];
	Matrix() { }
	Matrix(const int &n, const int &m) : n(n), m(m)
	{
		if(n == m)
			for(int i = 0; i < n; i ++)
				for(int j = 0; j < n; j ++)
					if(i == j)
						d[i][j] = 1;
					else
						d[i][j] = 0;
		else
			for(int i = 0; i < n; i ++)
				for(int j = 0; j < n; j ++)
					d[i][j] = 0;
	}
	Matrix(const int &n, const int &m, const vector <doublel> &from) : n(n), m(m)
	{
		int p = 0;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				d[i][j] = from[p ++];
	}
	void reset()
	{
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(i == j)
					d[i][j] = 1;
				else
					d[i][j] = 0;
	}
	Matrix operator *(const Matrix &rhs) const
	{
		Matrix ret(n, rhs.m);
		for(int i = 0; i < ret.n; i ++)
			for(int j = 0; j < ret.m; j ++)
			{
				ret.d[i][j] = 0;
				for(int k = 0; k < m; k ++)
					ret.d[i][j] += d[i][k] * rhs.d[k][j];
			}
		return ret;
	}
};

struct SegmentTree
{
	int l[N * 4], r[N * 4];
	Matrix flag[N * 4];
	bool is_unit[N * 4];
	SegmentTree() { }
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		is_unit[x] = true;
		flag[x] = Matrix(3, 3);
		if(left + 1 != right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void push(int x)
	{
		if(is_unit[x])
			return;
		if(l[x] + 1 != r[x])
		{
			/*
			bool ff = true;
			for(int i = 0; i < 3; i ++)
			{
				for(int j = 0; j < 3; j ++)
				{
					if(i == j && flag[x].d[i][j] != 1)
					{
						ff = false;
						break;
					}
					if(i != j && flag[x].d[i][j] != 0)
					{	
						ff = false;
						break;
					}
				}
				if(!ff)
					break;
			}
			if(ff)
				return;
			*/
			if(is_unit[2 * x])
			{
				flag[2 * x] = flag[x];
				is_unit[2 * x] = false;
			}
			else
				flag[2 * x] = flag[x] * flag[2 * x];
			if(is_unit[2 * x + 1])
			{
				flag[2 * x + 1] = flag[x];
				is_unit[2 * x + 1] = false;
			}
			else
				flag[2 * x + 1] = flag[x] * flag[2 * x + 1];
			flag[x].reset();
			is_unit[x] = true;
		}
	}
	void change(int left, int right, const Matrix &c, int x = 1)
	{
		push(x);
		if(left == l[x] && right == r[x])
		{
			if(l[x] + 1 == r[x])
				flag[x] = c * flag[x];
			else
				flag[x] = c;
			is_unit[x] = false;
		}
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(right <= mid)
				change(left, right, c, 2 * x);
			else if(left >= mid)
				change(left, right, c, 2 * x + 1);
			else
			{
				change(left, mid, c, 2 * x);
				change(mid, right, c, 2 * x + 1);
			}
		}
	}
	void query(int pos, Matrix &ans, int x = 1)
	{
		push(x);
		if(l[x] + 1 == r[x])
			ans = flag[x];
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(pos < mid)
				query(pos, ans, 2 * x);
			else
				query(pos, ans, 2 * x + 1);
		}
	}
}st;

int main()
{
	//Matrix(3, 1, {1, 2, 3});
	//ios :: sync_with_stdio(false);
	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	st.init(0, n + 1);
	Matrix que;
	while(m --)
	{
		int t, y, z;
		//cin >> t >> y >> z;
		scanf("%d%d%d", &t, &y, &z);
		st.query(y, que);
		Matrix to = que * Matrix(3, 1, {(doublel)y, 0, 1});
		st.query(y - 1, que);
		Matrix from = que * Matrix(3, 1, {y - 1.0, 0, 1});

		//cout << "------\n";
		//cout << from.d[0][0] << ' ' << from.d[1][0] << ' ' << to.d[0][0] << ' ' << to.d[1][0] << '\n';

		doublel dx = to.d[0][0] - from.d[0][0];
		doublel dy = to.d[1][0] - from.d[1][0];
		doublel len = sqrtl(dx * dx + dy * dy);
		if(t == 1)
		{
			dx = dx / len * z;
			dy = dy / len * z;
			st.change(y, n + 1, Matrix(3, 3, {1, 0, dx, 0, 1, dy, 0, 0, 1}));
		}
		else
		{
			dx = from.d[0][0];
			dy = from.d[1][0];
			st.change(y, n + 1, Matrix(3, 3, {1, 0, -dx, 0, 1, -dy, 0, 0, 1}));
			doublel co = cosl((360 - z) / 180.0 * Pi);
			doublel si = sinl((360 - z) / 180.0 * Pi);
			st.change(y, n + 1, Matrix(3, 3, {co, -si, 0, si, co, 0, 0, 0, 1}));
			st.change(y, n + 1, Matrix(3, 3, {1, 0, dx, 0, 1, dy, 0, 0, 1}));
		}
		st.query(n, que);
		Matrix last = que * Matrix(3, 1, {(doublel)n, 0, 1});
		//cout << setprecision(15) << last.d[0][0] << ' ' << last.d[1][0] << '\n';
		printf("%.6f %.6f\n", (double)last.d[0][0], (double)last.d[1][0]);
	}
	return 0;
}