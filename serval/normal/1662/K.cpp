#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);
const double s3 = sqrt(3.0);
const double oo = 1e18;

class Vec
{
public:
	double x, y;
	Vec(){}
	Vec(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double len()
	{
		return sqrt(x * x + y * y);
	}
	Vec norm()
	{
		double l = len();
		return Vec(x / l, y / l);
	}
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
	Vec rot(int deg)
	{
		if (deg == 1)
			return Vec(-y, x);
		if (deg == -1)
			return Vec(y, -x);
	}
	void print() const
	{
		printf("(%.10lf, %.10lf)\n", x, y);
	}
};

typedef Vec Point;

Vec operator + (const Vec &a, const Vec &b)
{
	return Vec(a.x + b.x, a.y + b.y);
}
Vec operator - (const Vec &a, const Vec &b)
{
	return Vec(a.x - b.x, a.y - b.y);
}
Vec operator * (double k, const Vec &a)
{
	return Vec(k * a.x, k * a.y);
}
double operator * (const Vec &a, const Vec &b)
{
	return a.x * b.x + a.y * b.y;
}
double operator ^ (const Vec &a, const Vec &b)
{
	return a.x * b.y - b.x * a.y;
}

Point A, B, C;

double Fermat(const Point &A, const Point &B, const Point &C)
{
	Vec AB = B - A, AC = C - A;
	if ((AB ^ AC) < 0)
		swap(AB, AC);
	Point mB = A + 0.5 * AB, mC = A + 0.5 * AC;
	Vec rB = AB.norm().rot(-1), rC = AC.norm().rot(1);
	Point OB = mB + 0.5 * AB.len() / s3 * rB;
	Point OC = mC + 0.5 * AC.len() / s3 * rC;
	Vec OBA = A - OB, OBC = (OC - OB).norm();
	OBA = OBA - (OBA * OBC) * OBC;
	Point F = A - 2 * OBA;
	return (A - F).len() + (B - F).len() + (C - F).len();
}

double calc(const Point &A, const Point &B, const Point &C)
{
	double ret = oo;
	ret = min(ret, (B - A).len() + (C - A).len());
	ret = min(ret, (A - B).len() + (C - B).len());
	ret = min(ret, (A - C).len() + (B - C).len());
	ret = min(ret, Fermat(A, B, C));
	return ret;
}

double check(const Point &P)
{
	double ret = 0;
	ret = max(ret, calc(P, A, B));
	ret = max(ret, calc(P, A, C));
	ret = max(ret, calc(P, B, C));
	return ret;
}

Vec AB, AC;

double find(double u)
{
	double vL = 0, vR = 1 - u;
	for (int i = 1; i <= 100; i++)
	{
		double vm = (vR - vL) / 3;
		double vl = vL + vm, vr = vR - vm;
		if (check(A + u * AB + vl * AC) < check(A + u * AB + vr * AC))
			vR = vr;
		else
			vL = vl;
	}
	return check(A + u * AB + (vL + vR) / 2 * AC);
}

int main()
{
	A.read();
	B.read();
	C.read();
	AB = B - A;
	AC = C - A;
	double uL = 0, uR = 1;
	for (int i = 1; i <= 100; i++)
	{
		double um = (uR - uL) / 3;
		double ul = uL + um, ur = uR - um;
		if (find(ul) < find(ur))
			uR = ur;
		else
			uL = ul;
	}
	printf("%.10lf\n", find((uL + uR) / 2));
	return 0;
}