#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const double eps = 1e-12;

int n;
double l, v1, v2;
double p[maxN];
double a[maxN + maxN];

set < pair < double, pair < int, int > > > S;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%lf%lf%lf", &n, &l, &v1, &v2);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", &a[i]);
	for (int i = n; i >= 1; --i)
		a[i] -= a[1];
	for (int i = n + 1; i <= n + n; ++i)
		a[i] = a[i - n] + 2.0 * l;

	double d = l * v2 / (v1 + v2);
	for (int i = 1; i <= 2 * n; ++i) {
		S.insert(make_pair(a[i], make_pair(i, -1)));
		S.insert(make_pair(a[i] - d, make_pair(i, +1)));
	}
	S.insert(make_pair(2.0 * l, make_pair(0, 0)));

	double old_time = 0.0;
	int cnt = 0;
	while (true) {
		pair < double, pair < int, int > > v = * S.begin(); S.erase(S.begin());
		if (v.first < -eps) {
			++cnt;
			continue;
		}

		if (v.second.second == +1) {
			p[cnt] += v.first - old_time;
			++cnt;
			old_time = v.first;
		} else if (v.second.second == -1) {
			p[cnt] += v.first - old_time;
			--cnt;
			old_time = v.first;
		} else {
			p[cnt] += v.first - old_time;
			break;
		}
	}

	for (int i = 0; i <= n; ++i)
		printf("%.10lf\n", p[i] / (2.0 * l));

	return 0;
}