#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const double pi = std::acos(-1.);

struct P {
	double x, y;
	P() : x(0.), y(0.) { }
	P(double x, double y) : x(x), y(y) { }
} o, zero;

double operator^(P a, P b) {
	return a.x*b.y - a.y*b.x;
}
P operator-(P a, P b) {
	return P(a.x-b.x, a.y-b.y);
}

int N;
std::vector<P> p;
double min = 1e9, max;

void go(double r) {
	domin(min, r);
	domax(max, r);
}
double dist(P a, P b) {
	double x = a.x-b.x, y = a.y-b.y;
	return std::sqrt(x*x + y*y);
}
double f(double r) {
	return pi*r*r;
}
P perp(P a) {
	return P(-a.y, a.x);
}

int main()
{
	scanf("%d%lf%lf", &N, &o.x, &o.y);
	p.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		p[i].x -= o.x;
		p[i].y -= o.y;
	}
	for (int i = 0; i < N; i++) {
		int j = (i+1) % N;
		go(dist(p[i], zero));
		P a = perp(p[j] - p[i]);
		if ((p[i] ^ a) * (p[j] ^ a) < 0) {
			go(std::abs(p[i] ^ p[j]) / dist(p[i], p[j]));
		}
	}
	printf("%.8lf\n", f(max) - f(min));
}