#include <bits/stdc++.h>
#include <complex.h>

using namespace std;
using nagai = long long;
using db = long long;
using cp = long long _Complex;
using pol = vector<cp>;

#define re(x) __real__ (x)
#define im(x) __imag__ (x)

db eps = 1e-7;

istream& operator >>(istream& a, cp& b)
{
	db x, y;
	a >> x >> y;
	re(b) = x;
	im(b) = y;
	return a;
}

ostream& operator <<(ostream& a, const cp b)
{
	 return a << re(b) << ' ' << im(b);
}

db cross(cp a, cp b)
{
	return re(a) * im(b) - re(b) * im(a);
}

db dot(cp a, cp b)
{
	 return re(a) * re(b) + im(a) * im(b);
}

cp intersect(cp a, cp b, cp c, cp d)
{
	db massa = cross(c - b, d - b);
	db massb = cross(c - a, d - a);
	return (a * massa + b * massb) / (massa + massb);
}

db dist(cp a, cp b, cp c)
{
	 return cross(c - a, b - a) / cabs(b - c);
}

db dist_seg(cp a, cp b, cp c)
{
	if (dot(a - b, c - b) <= 0 || dot(a - c, b - c) <= 0)
		return min(cabs(a - b), cabs(a - c));
	return abs(dist(a, b, c));
}

cp reflect(cp a, cp b, cp c)
{
	cp vec = (c - b);
	vec *= cp{0, 1};
	vec *= dist(a, b, c) / cabs(vec);
	a += vec * (db)2;
	return a;
}

cp project(cp a, cp b, cp c)
{
	cp vec = (c - b);
	vec *= cp{0, 1};
	vec *= dist(a, b, c) / cabs(vec);
	a += vec;
	return a;
}

cp neut = {-228, 1488};


cp inter(cp a, cp b, cp c, cp d)
{
	db kek = cross(d - b, c - b);
	db mem = cross(c - a, d - a);
	if (cabs(kek + mem) < eps)
		return neut;
	return (a * kek + b * mem) / (mem + kek);
}

int sgn(db x)
{
	 return (x > eps) - (x < -eps);
}

int check_inter(cp a, cp b, cp c, cp d)
{
	int s1, s2, s3, s4;
	s1 = sgn(cross(c - a, d - a));
	s2 = sgn(cross(c - b, d - b));
	s3 = sgn(cross(c - a, c - b));
	s4 = sgn(cross(d - a, d - b));
	bool ans = (s1 != s2 || s1 == 0 && s2 == 0) && (s3 != s4 || s3 == 0 && s4 == 0);
	if (ans)
	{
		if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0)
			return 1;
		return 2;
	}
	return 0;
}

db area(pol p)
{
	db ans = 0;
	for (int i = 0; i < p.size(); ++i)
	{
		 int j = i + 1 == p.size() ? 0 : i + 1;
		 ans += cross(p[i], p[j]);
	}
	return abs(ans) / 2;
}

db perim(pol p)
{
	db ans = 0;
	for (int i = 0; i < p.size(); ++i)
	{
		 int j = i + 1 == p.size() ? 0 : i + 1;
		 ans += cabs(p[i] - p[j]);
	}
	return ans;
}

pair<cp, cp> getpts(db a, db b, db c)
{
	if (a == 0)
	{
		db y = -c / b;
		return make_pair(cp{0, y}, cp{100, y});
	}
	db x1 = (-c - 0 * b) / a;
	db x2 = (-c - 100 * b) / a;
	return make_pair(cp{x1, 0}, cp{x2, 100});
}

pair<cp, cp> circle_line(cp cent, db rad, cp a, cp b)
{
	cp kek = project(cent, a, b);
	db dist = cabs(kek - cent);
	if (abs(dist - rad) < eps)
		return {kek, kek};
	if (dist > rad)
		return {neut, neut};
	db memos = sqrt(rad * rad - dist * dist);
	cp vec = b - a;
	vec /= cabs(vec);
	vec *= memos;
	return {kek + vec, kek - vec};
	// centkek ** 2 + t*abs(vec) = centmem**2 
}

pair<cp, cp> circle_circle(cp c1, db r1, cp c2, db r2)
{
	db dist = cabs(c1 - c2);
	if (dist > r1 + r2 + eps)
	{
		 return {neut, 0};
	}
	if (dist < eps && abs(r1 - r2) < eps)
	{
		return {neut, 1};
	}
	if (dist < abs(r1 - r2))
	{
		return {neut, 0};
	}
	db diff = (r1 * r1 - r2 * r2) / dist;
	db x = (dist + diff) / 2;
	db y = dist - x;
	cp vec = (c2 - c1);
	vec /= cabs(vec);
	cp kek = c1 + vec * x;
	vec *= cp{0, 1};
	db dist1 = sqrt(r1 * r1 - x * x);
	return {kek + vec * dist1, kek - vec * dist1};
}

using pol = vector<cp>;

pol ch1(pol p)
{
	vector<cp> mem;
	for (auto& x : p)
	{
		while (mem.size() >= 2 && cross(x - mem[mem.size() - 2], mem.back() - mem[mem.size() - 2]) >= 0)
			mem.pop_back();
		mem.push_back(x);
	}
	return mem;
}

pol ch(pol p)
{
	sort(p.begin(), p.end(), [&](cp a, cp b)
			{
			 if (re(a) != re(b))
			 return re(a) < re(b);
			 return im(a) < im(b);
			});
	p.erase(unique(p.begin(), p.end()), p.end());
	if (p.size() == 1)
		return p;
	auto memos = ch1(p);
	memos.pop_back();
	reverse(p.begin(), p.end());
	for (auto& x : ch1(p))
		memos.push_back(x);
	memos.pop_back();
	return memos;
}

db cnorm(cp x)
{
	return dot(x, x);
}

bool belong(cp pt, pol p)
{
	cp pt1 = {22820934, 1488102213};
	int n = p.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cabs(p[i] - pt) < eps)
		{
			return true;
		}
		if (check_inter(pt, pt1, p[i], p[(i + 1) % n]))
			++cnt;
	}
	return (cnt % 2 == 1);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(30);
	int n;
	cin>>n;
	pol kek(n);
	for(auto&x:kek)cin>>x,im(x)-=re(x)*re(x);
	auto mem=ch(kek);
	int ans=0;
//	cerr<<mem.size()<<'\n';
	for(int i=0;i<mem.size();++i){
		auto p1=mem[i],p2=mem[(i+1)%mem.size()];
		if(re(p2)<re(p1))++ans;
	}
	cout<<ans<<'\n';
	return 0;
}