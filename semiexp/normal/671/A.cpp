#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int Ax, Ay, Bx, By, Tx, Ty;
int N, Xi[101010], Yi[101010];

double comp(double a, double b)
{
	return sqrt(a * a + b * b);
}

pair<double, int> ha[101010], hb[101010];

int main()
{
	scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Tx, &Ty);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d%d", Xi + i, Yi + i);

	if (N == 1) {
		printf("%.10f\n", min(comp(Ax - Xi[0], Ay - Yi[0]), comp(Bx - Xi[0], By - Yi[0])) + comp(Xi[0] - Tx, Yi[0] - Ty));
		return 0;
	}

	double ddist = 0;
	for (int i = 0; i < N; ++i) {
		double base = comp(Tx - Xi[i], Ty - Yi[i]);
		ddist += 2 * base;
		ha[i] = make_pair(base - comp(Ax - Xi[i], Ay - Yi[i]), i);
		hb[i] = make_pair(base - comp(Bx - Xi[i], By - Yi[i]), i);
	}
	sort(ha, ha + N);
	sort(hb, hb + N);
	reverse(ha, ha + N);
	reverse(hb, hb + N);

	double cand = ddist;
	if (ha[0].second != hb[0].second) {
		cand -= ha[0].first + hb[0].first;
	} else {
		cand -= max(ha[0].first + hb[1].first, ha[1].first + hb[0].first);
	}
	ddist = min(cand, ddist - max(ha[0].first, hb[0].first));
	printf("%.10f\n", ddist);

	return 0;
}