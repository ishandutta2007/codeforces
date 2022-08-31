#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

struct Rat
{
	i64 a, b;
	Rat(i64 x = 0, i64 y = 1) {
		if (y > 0) {
			a = x; b = y;
		} else {
			a = -x; b = -y;
		}
	}
};

inline bool operator<(const Rat &a, const Rat &b)
{
	i64 pa = a.a / a.b, pb = b.a / b.b;
	if (pa < pb) return true;
	if (pa > pb) return false;
	return a.a % a.b * b.b < b.a % b.b * a.b;
}
inline bool operator==(const Rat &a, const Rat &b)
{
	return !(a < b || b < a);
}

int N;
int ax1, ay1, ax2, ay2;

pair<Rat, Rat> hittime(int x, int v, int lo, int hi)
{
	if (v == 0) {
		if (lo < x && x < hi) return {Rat(0), Rat(10000000)};
		else return {Rat(1), Rat(0)};
	}
	if (x < lo) {
		if (v < 0) return {Rat(1), Rat(0)};
		else return {Rat(lo - x, v), Rat(hi - x, v)};
	}
	if (hi < x) {
		if (v > 0) return {Rat(1), Rat(0)};
		return {Rat(x - hi, -v), Rat(x - lo, -v)};
	}
	if (v > 0) return {Rat(0), Rat(hi - x, v)};
	return {Rat(0), Rat(x - lo, -v)};
}

int main()
{
	scanf("%d", &N);
	scanf("%d%d%d%d", &ax1, &ay1, &ax2, &ay2);

	Rat lo(0), hi(10000000);
	for (int i = 0; i < N; ++i) {
		int rx, ry, vx, vy;
		scanf("%d%d%d%d", &rx, &ry, &vx, &vy);

		auto hx = hittime(rx, vx, ax1, ax2);
		auto hy = hittime(ry, vy, ay1, ay2);
		lo = max(lo, hx.first);
		lo = max(lo, hy.first);
		hi = min(hi, hx.second);
		hi = min(hi, hy.second);
	}
	if (lo < hi) {
		printf("%.10f\n", (double)lo.a / lo.b);
	} else puts("-1");
	return 0;
}