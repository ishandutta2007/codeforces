#include <bits/stdc++.h> 


using namespace std;


#define int long long 
#define double long double

struct point
{
	double x, y;
	point(double val1, double val2)
	{
		x = val1;
		y = val2;
	}
	point()
	{
		x = 0;
		y = 0;
	}
};


struct line
{
	double a, b, c;
	line()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	line(point A, point B)
	{
		a = (B.y - A.y);
		b = (A.x - B.x);
		c = ((-1) * (a * A.x + b * A.y));
	}
	line(double val1, double val2, double val3)
	{
		a = val1;
		b = val2;
		c = val3;
	}
};


struct circle
{
	point o;
	double r;
	circle()
	{
		o = point(0, 0);
		r = 1;
	}
	circle(point p, double val)
	{
		o = p;
		r = val;
	}
	circle(double x, double y, double val)
	{
		o.x = x;
		o.y = y;
		r = val;
	}
};


void swap(point &a, point &b)
{
	swap(a.x, b.x);
	swap(a.y, b.y);
}


void swap(line a, line b)
{
	swap(a.a, b.a);
	swap(a.b, b.b);
	swap(a.c, b.c);
}


void swap(circle &a, circle &b)
{
	swap(a.o, b.o);
	swap(a.r, b.r);
}


point operator+(point a, point b)
{
	point c(a.x + b.x, a.y + b.y);
	return c;
}


point operator-(point a, point b)
{
	point c(a.x - b.x, a.y - b.y);
	return c;
}


double operator*(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}


double operator^(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}


bool operator==(point a, point b)
{
	return a.x == b.x && a.y == b.y;
}


bool operator==(line a, line b)
{
	return a.a == b.a && a.b == b.b && a.c == b.c;
}


bool operator==(circle a, circle b)
{
	return a.o == b.o && a.r == b.r;
}


istream& operator>>(istream& stream, line &a)
{
	stream >> a.a >> a.b >> a.c;
	return stream;
}


istream& operator>>(istream& stream, point &a)
{
	stream >> a.x >> a.y;
	return stream;
}


istream& operator>>(istream& stream, circle &a)
{
	stream >> a.o >> a.r;
	return stream;
}


ostream& operator<<(ostream& stream, point &a)
{
	stream << a.x << " " << a.y << " ";
	return stream;
}


ostream& operator<<(ostream& stream, line &a)
{
	stream << a.a << " " << a.b << " " << a.c;
	return stream;
}


ostream& operator<<(ostream& stream, circle &a)
{
	stream << a.o << a.r;
	return stream;
}


double angle(point a, point b, point c)
{
	return atan2((a - b) ^ (c - b), (a - b)*(c - b));
}


double twSpace(point a, point b, point c)
{
	return (a - b) ^ (c - b);
}


double dist(point a, point b)
{
	double f = a.x - b.x, s = a.y - b.y;
	return sqrt(f*f + s * s);
}


double lineDist(point a, point b, point c)
{
	return (double)(abs(twSpace(a, b, c))) / dist(b, c);
}


double rayDist(point a, point b, point c)
{
	if (((c - b)*(a - b)) < 0)
	{
		return dist(a, b);
	}
	return lineDist(a, b, c);
}


double segmentDist(point a, point b, point c)
{
	if (((c - b)*(a - b)) < 0)
	{
		return dist(a, b);
	}
	if (((b - c)*(a - c)) < 0)
	{
		return dist(a, c);
	}
	return lineDist(a, b, c);
}

bool insideAngle(point a, point o, point b, point p)
{
	if (((b - o) ^ (a - o)) < 0)
	{
		swap(a, b);
	}
	if (((b - o) ^ (p - o)) >= 0 && ((a - o) ^ (p - o)) <= 0)
	{
		return true;
	}
	return false;
}



bool rayCross(point a, point b, point c, point d)
{
	if (((b - a) ^ (c - a)) == 0)
	{
		return (rayDist(c, a, b) == 0) || (rayDist(a, c, d) == 0);
	}
	return insideAngle(a, c, c + b - a, d) && ((b - a) ^ (d - c)) != 0;
}


bool segmentCross(point a, point b, point c, point d)
{
	return (rayCross(a, b, c, d)) && (rayCross(b, a, c, d)) && (rayCross(a, b, d, c)) && (rayCross(b, a, d, c));
}


double segmentSegmentDist(point a, point b, point c, point d)
{
	if (segmentCross(a, b, c, d))
	{
		return 0.0;
	}
	return min(min(segmentDist(a, c, d), segmentDist(b, c, d)), min(segmentDist(c, a, b), segmentDist(d, a, b)));
}


bool segmentRayCross(point a, point b, point c, point d)
{
	return rayCross(a, b, c, d) && rayCross(b, a, c, d);
}


double segmentRayDist(point a, point b, point c, point d)
{
	if (segmentRayCross(a, b, c, d))
	{
		return 0.0;
	}
	return min(min(rayDist(a, c, d), rayDist(b,
		c, d)), segmentDist(c, a, b));
}


bool segmentLineCross(point a, point b, point c, point d)
{
	return segmentRayCross(a, b, c, d) || segmentRayCross(a, b, d, c);
}


double segmentLineDist(point a, point b, point c, point d)
{
	if (segmentLineCross(a, b, c, d))
	{
		return 0.0;
	}
	return min(lineDist(a, c, d), lineDist(b, c, d));
}


double rayRayDist(point a, point b, point c, point d)
{
	if (rayCross(a, b, c, d))
	{
		return 0.0;
	}
	return min(rayDist(a, c, d), rayDist(c, a, b));
}


bool rayLineCross(point a, point b, point c, point d)
{
	return rayCross(a, b, c, d) || rayCross(a, b, d, c);
}


double rayLineDist(point a, point b, point c, point d)
{
	if (rayLineCross(a, b, c, d))
	{
		return 0.0;
	}
	return lineDist(a, c, d);
}


bool lineLineCross(point a, point b, point c, point d)
{
	return rayLineCross(a, b, c, d) || rayLineCross(b, a, c, d);
}


double lineLineDist(point a, point b, point c, point d)
{
	if (lineLineCross(a, b, c, d))
	{
		return 0.0;
	}
	return lineDist(a, c, d);
}


double lineDist(point a, line t)
{
	return (double)abs(t.a * a.x + t.b * a.y + t.c) / sqrt((double)(t.a * t.a + t.b * t.b));
}


point cross(line f, line s)
{
	double ansx, ansy;
	if (s.a == 0 || s.b == 0)
	{
		swap(f, s);
	}
	if (f.a == 0)
	{
		ansy = (-1) * (f.c / f.b);
		ansx = (-1) * (s.b * ansy + s.c) / s.a;
	}
	else if (f.b == 0)
	{
		ansx = (-1) * f.c / f.a;
		ansy = (-1) * (ansx * s.a + s.c) / s.b;
	}
	else
	{
		ansy = (f.c * s.a - f.a * s.c) / (f.a * s.b - f.b * s.a);
		ansx = (f.c * s.b - s.c * f.b) / (s.a * f.b - f.a * s.b);
	}
	point a(ansx, ansy);
	return a;
}


double value(point p, line l)
{
	return p.x * l.a + p.y * l.b + l.c;
}

void l()
{
	while (true) {};
}


line perp(line l, point p)
{
	point norm(l.a, l.b);
	line ans(p, p + norm);
	return ans;
}


point medianCross(point a, point b, point c)
{
	point m1((a.x + b.x) / 2, (a.y + b.y) / 2), m2((a.x + c.x) / 2, (a.y + c.y) / 2);
	line cm1(c, m1), bm2(b, m2);
	point ans = cross(cm1, bm2);
	return ans;
}




point turn(point a, double alpha)
{
	double x = a.x, y = a.y;
	point ans(x * cos(alpha) - y * sin(alpha), y * cos(alpha) + x * sin(alpha));
	return ans;
}


line bisector(point a, point b, point c)
{
	double alpha = angle(a, b, c);
	line ans(b, b + turn(a - b, alpha / 2));
	point temp = turn(a - b, alpha / 2);
	return ans;
}


point incenter(point a, point b, point c)
{
	line f = bisector(a, b, c), s = bisector(b, c, a);
	return cross(f, s);
}


point middle(point a, point b)
{
	point ans((a.x + b.x) / 2, (a.y + b.y) / 2);
	return ans;
}


point center(point a, point b, point c)
{
	point m1 = middle(a, b), m2 = middle(b, c);
	line ab(a, b), bc(b, c);
	line f = perp(ab, m1), s = perp(bc, m2);
	point ans = cross(f, s);
	return ans;
}


point changeSize(point a, double d)
{
	double temp = sqrt(a.x * a.x + a.y * a.y);
	a.x *= (d / temp);
	a.y *= (d / temp);
	return a;
}


double sq(double a)
{
	return a * a;
}


vector<point> cross(line l, circle c)
{
	point t = c.o;
	l.c += l.a * c.o.x + l.b * c.o.y;
	vector<point> ans;
	point O(0, 0);
	line k = perp(l, O);
	point temp = cross(k, l);
	if (dist(temp, O) > c.r)
	{
		return ans;
	}
	if (dist(temp, O) == c.r)
	{
		ans.push_back(temp + c.o);
		return ans;
	}
	double dist = sqrt(sq(c.r) - (sq(l.c)) / (sq(l.a) + sq(l.b)));
	//(sq(l.c)) / (sq(l.a) + sq(l.b)) is distance between O and l; 
	point step((-1) * l.b, l.a);
	ans.push_back(c.o + temp + changeSize(step, dist));
	ans.push_back(c.o + temp - changeSize(step, dist));
	return ans;
}



vector<point> cross(circle a, circle b)
{
	if (sq(a.o.x - b.o.x) + sq(a.o.y - b.o.y) == sq(a.r + b.r))
	{
		vector
			<point>ans;
		ans.push_back(a.o + changeSize(b.o - a.o, a.r));
		return ans;
	}
	if (sq(a.o.x - b.o.x) + sq(a.o.y - b.o.y) == sq(a.r - b.r))
	{

		if (b.r > a.r)
		{
			swap(a, b);
		}
		vector<point>ans;
		ans.push_back(a.o + changeSize(b.o - a.o, a.r));
		return ans;
	}
	if (sq(a.o.x - b.o.x) + sq(a.o.y - b.o.y) > sq(a.r + b.r) || sq(a.o.x - b.o.x) + sq(a.o.y - b.o.y) < sq(a.r - b.r))
	{
		vector<point>ans;
		return ans;
	}
	line temp(2 * a.o.x - 2 * b.o.x, 2 * a.o.y - 2 * b.o.y, sq(b.o.x) + sq(b.o.y) - sq(a.o.x) - sq(a.o.y) - sq(b.r) + sq(a.r));
	//cout << a << endl; 
	return cross(temp, a);
}


vector <point> findTouch(point p, circle c)
{
	vector <point> ans;
	if (sq(c.o.x - p.x) + sq(c.o.y - p.y) < sq(c.r))
	{
		return ans;
	}
	if (sq(c.o.x - p.x) + sq(c.o.y - p.y) == sq(c.r))
	{
		ans.push_back(p);
		return ans;
	}
	double a1 = c.o.x, b1 = c.o.y, a2 = p.x, b2 = p.y, r = c.r;
	line key(2 * a1 - 2 * a2, 2 * b1 - 2 * b2, sq(a2) + sq(b2) - sq(a1) - sq(b1) + 2 * sq(r) - sq(a1 - a2) - sq(b1 - b2));
	return cross(key, c);
}

line makeBiss(point x, point y, point z)
{
  point Y = z - x;
  double b = sqrt(Y.x*Y.x + Y.y*Y.y);
  Y = point(Y.x / b, Y.y/ b);


  point X = y - x;
  double a = sqrt(X.x*X.x + X.y*X.y);
  X = point(X.x / a, X.y/ a);  
  point m = X+Y;
  return (line(x, m+x));
}

bool iz_perp(point a, point b, point c)
{
  a = a - c;
  b = b - c;
  if (a.x*b.x + a.y*b.y == 0)
    return true;
  return false;
}

bool iz_on_line(line a, point x)
{
  return a.a*x.x + a.b*x.y + a.c == 0;
}

signed main()
{
	//freopen("input.txt", "r", stdin); 
	cout.precision(20);
  line a;
  point b, c;
  cin >> a >> b >> c;
  double ans = abs((b.x - c.x)) + abs((b.y - c.y));
  
  point b1 = cross(a, line(1, 0, -b.x));
  point b2 = cross(a, line(0, 1, -b.y));
  point c1 = cross(a, line(1, 0, -c.x));
  point c2 = cross(a, line(0, 1, -c.y));

  ans = min(ans, dist(b, b1) + dist(b1, c1) + dist(c1, c));
  
  ans = min(ans, dist(b, b1) + dist(b1, c2) + dist(c2, c));
  
  ans = min(ans, dist(b, b2) + dist(b2, c1) + dist(c1, c));
  
  ans = min(ans, dist(b, b2) + dist(b2, c2) + dist(c2, c));
 
  cout << ans;
  return 0;
}