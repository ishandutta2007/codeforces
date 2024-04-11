#include <bits/stdc++.h>
using namespace std;

const int N = 121;
const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y, z;
	Point operator +(Point p) {
		return {x + p.x, y + p.y, z + p.z};
	}
	Point operator -(Point p) {
		return {x - p.x, y - p.y, z - p.z};
	}
	Point operator *(double d) {
		return {x * d, y * d, z * d};
	}
	Point operator /(double d) {
		return {x / d, y / d, z / d};
	}
	double dot(Point p) {
		return x * p.x + y * p.y + z * p.z;
	}
	double len2() {
		return x * x + y * y + z * z;
	}
}p[N], o[N], res;
int n, cnt;
double r, tmp;

double det(double m[3][3])
{
	double *t = &m[0][0];
	double a = t[0] * t[4] * t[8];
	double b = t[0] * t[5] * t[7];
	double c = t[1] * t[5] * t[6];
	double d = t[1] * t[3] * t[8];
	double e = t[2] * t[3] * t[7];
	double f = t[2] * t[4] * t[6];
	return a - b + c - d + e - f;
}

void ball()
{
	Point q[3];
	double m[3][3], sol[3], l[3], d;
	res = {0, 0, 0};
	r = 0;
	switch(cnt) {
		case 1:
			res = o[0];
			break;
		case 2:
			res = (o[0] + o[1]) / 2;
			r = (res - o[0]).len2();
			break;
		case 3:
			for(int i = 0; i < 2; i ++)
				q[i] = o[i + 1] - o[0];
			for(int i = 0; i < 2; i ++)
				for(int j = 0; j < 2; j ++)
					m[i][j] = q[i].dot(q[j]) * 2;
			for(int i = 0; i < 2; i ++)
				sol[i] = q[i].len2();
			d = m[0][0] * m[1][1] - m[0][1] * m[1][0];
			if(sgn(d) == 0)
				return;
			l[0] = (sol[0] * m[1][1] - sol[1] * m[0][1]) / d;
			l[1] = (sol[1] * m[0][0] - sol[0] * m[1][0]) / d;
			res = o[0] + q[0] * l[0] + q[1] * l[1];
			r = (res - o[0]).len2();
			break;
		case 4:
			for(int i = 0; i < 3; i ++)
			{
				q[i] = o[i + 1] - o[0];
				sol[i] = q[i].len2();
			}
			for(int i = 0; i < 3; i ++)
				for(int j = 0; j < 3; j ++)
					m[i][j] = q[i].dot(q[j]) * 2;
			d = det(m);
			if(sgn(d) == 0)
				return;
			for(int j = 0; j < 3; j ++)
			{
				for(int i = 0; i < 3; i ++)
					m[i][j] = sol[i];
				l[j] = det(m) / d;
				for(int i = 0; i < 3; i ++)
					m[i][j] = q[i].dot(q[j]) * 2;
			}
			res = o[0];
			for(int i = 0; i < 3; i ++)
				res = res + q[i] * l[i];
			r = (res - o[0]).len2();
	}
}

void mb(int m)
{
	ball();
	if(cnt < 4)
		for(int i = 0; i < m; i ++)
			if(sgn((res - p[i]).len2(), r) > 0)
			{
				o[cnt ++] = p[i];
				mb(i);
				cnt --;
				if(i > 0)
				{
					Point t = p[i];
					memmove(&p[1], &p[0], sizeof(Point) * i);
					p[0] = t;
				}
			}
}

double mininal_ball()
{
	r = -1;
	for(int i = 0; i < n; i ++)
		if(sgn((res - p[i]).len2(), r) > 0)
		{
			cnt = 1;
			o[0] = p[i];
			mb(i);
		}
	return sqrt(r);
}

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	srand(233);
	random_shuffle(p, p + n);
	mininal_ball();
	cout << setprecision(12) << res.x << ' ' << res.y << ' ' << res.z << '\n';
	return 0;
}