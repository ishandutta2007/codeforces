#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
#define lc (n*2+1)
#define rc (n*2+2)
#define nm ((nl+nr)/2)
#define len first
#define ang second
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;
typedef long double real;
typedef std::pair<real, real> V;

const int Max = 1<<19, MaxNodes = 1<<20;
const real pi = std::acos(-1.L);

V add(V a, V b) {
	std::complex<real> c(std::polar(a.len, a.ang) + std::polar(b.len, b.ang));
	return {std::abs(c), std::arg(c)};
}

struct RT {
	V v[MaxNodes];
	real ang[MaxNodes];
	void rot(int n, int nl, int nr, int ul, int ur, real uv) {
		if (ul <= nl && nr <= ur) {
			v[n].ang += uv;
			ang[n] += uv;
		} else {
			if (ul < nm) rot(lc, nl, nm, ul, ur, uv);
			if (nm < ur) rot(rc, nm, nr, ul, ur, uv);
			v[n] = add(v[lc], v[rc]);
			v[n].ang += ang[n];
		}
	}
	void ext(int n, int nl, int nr, int ui, real uv) {
		if (nl == ui && ui+1 == nr) {
			v[n].len += uv;
		} else {
			if (ui < nm) ext(lc, nl, nm, ui, uv);
			else ext(rc, nm, nr, ui, uv);
			v[n] = add(v[lc], v[rc]);
			v[n].ang += ang[n];
		}
	}
	void print() {
		std::complex<real> c(std::polar(v[0].len, v[0].ang));
		printf("%.6lf %.6lf\n", double(std::real(c)), double(std::imag(c)));
	}
} rt;

int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) rt.v[Max-1 + i].len = 1;
	for (int i = Max-2; i >= 0; i--) rt.v[i] = add(rt.v[i*2+1], rt.v[i*2+2]);
	for (int i = 0; i < M; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z); y--;
		if (x == 1) rt.ext(0, 0, Max, y, z);
		else rt.rot(0, 0, Max, y, N, -z * pi / 180);
		rt.print();
	}
}