#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int INF = 1000000000;
const Int INF2 = 1LL * INF * INF;
const int MAX = 300007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

struct Matrix
{
	double a[2][2];
	Matrix()
	{
		FILL(a , 0);
	}
	void init()
	{
		a[0][0] = a[1][1] = 1;
		a[0][1] = a[1][0] = 0;
	}
};

Matrix mult(Matrix a , Matrix b)
{
	Matrix c;
	FOR(i,0,2)
		FOR(j,0,2)
			FOR(k,0,2)
				c.a[i][k] += a.a[i][j] * b.a[j][k];
	return c;
}

PDD mult(Matrix a, PDD b)
{
	return MP(a.a[0][0] * b.first + a.a[0][1] * b.second , a.a[1][0] * b.first + a.a[1][1] * b.second);
}

PDD A[MAX];
PDD T[4 * MAX];
Matrix P[4 * MAX];

Matrix ang(double a)
{
	a /= 180;
	a *= acos(-1.0);
	a = -a;
	Matrix M;
	M.a[0][0] = M.a[1][1] = cos(a);
	M.a[0][1] = -sin(a);
	M.a[1][0] = sin(a);
	return M;
}

PDD f(PDD a, int len)
{
	double d = sqrt(a.first * a.first + a.second * a.second);
	a.first *= (d + len) / d;
	a.second *= (d + len) / d;
	return a;
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		T[v] = A[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v + 1 , l, m);
	build(2 * v + 2 , m + 1 , r);
	T[v].first = T[2 * v + 1].first + T[2 * v + 2].first;
	T[v].second = T[2 * v + 1].second + T[2 * v + 2].second;
}

void Push(int v)
{
	if (2 * v + 1 < 4 * MAX)
	{
		P[2 * v + 1] = mult(P[2 * v + 1] , P[v]);
		T[2 * v + 1] = mult(P[v], T[2 * v + 1] );
	}
	if (2 * v + 2 < 4 * MAX)
	{
		P[2 * v + 2] = mult(P[2 * v + 2] , P[v]);
		T[2 * v + 2] = mult(P[v] , T[2 * v + 2]);
	}
	P[v].init();
}

PDD get(int v , int l, int r, int L, int R)
{
	if (L > R) return MP(0,0);
	Push(v);
	if (l == L && r == R)
	{
		return T[v];
	}
	int m = (l + r) / 2;
	PDD A = get(2 * v + 1 , l, m , L, min(m, R));
	PDD B = get(2 * v + 2 , m + 1 , r , max(L, m + 1) , R);
	return MP(A.first + B.first , A.second + B.second);
}

Matrix matr;
void mult(int v, int l, int r, int L, int R)
{
	//cout << v << ' ' << l << ' ' << r << ' ' << L << ' ' << R << endl;
	if (L > R) return;
	Push(v);
	if (l == L && r == R)
	{
		P[v] = mult(P[v] , matr);
		T[v] = mult(matr, T[v]);
		return;
	}
	int m = (l + r) / 2;
	mult(2 * v + 1 , l, m , L, min(m, R));
	mult(2 * v + 2 , m + 1 , r , max(L, m + 1) , R);
	T[v].first = T[2 * v + 1].first + T[2 * v + 2].first;
	T[v].second = T[2 * v + 1].second + T[2 * v + 2].second;
}

void upd(int v, int l, int r, int pos, int len)
{
	Push(v);
	if (l == r)
	{
		T[v] = f(T[v] , len);
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m)
		upd(2 * v + 1 , l, m, pos, len);
	else
		upd(2 * v + 2 , m + 1 , r, pos, len);
	T[v].first = T[2 * v + 1].first + T[2 * v + 2].first;
	T[v].second = T[2 * v + 1].second + T[2 * v + 2].second;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);
	//freopen("out.txt" , "w" , stdout);

	int n , m;
	cin >> n >> m;
	FOR(i,0,n)
	{
		A[i] = MP(1, 0);
	}

	FOR(i,0,4 * MAX)
	{
		P[i].init();
	}

	build(0,0,n - 1);

	FOR(i,0,m)
	{
		int x , y , z;
		scanf("%d%d%d" , &x , &y , &z);
		if (x == 1)
		{
			--y;
			upd(0,0,n - 1,y,z);
		}
		else
		{
			matr = ang(z);
			--y;
			mult(0,0,n - 1 , y, n - 1);
		}
		PDD r = get(0,0,n - 1, 0, n - 1);
		printf("%.10f %.10f\n" , r.first, r.second);
	}


    return 0;
}