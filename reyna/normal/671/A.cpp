// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e5 + 5, mod = 0;

long long sqr(int x) { return x * 1ll * x; }

long double dis(pair<int, int> x, pair<int, int> y) {
	return sqrt(sqr(x.first - y.first) + sqr(x.second - y.second));
}

int px[N], py[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ax, ay, bx, by, tx, ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
	rep(i, n)
		cin >> px[i] >> py[i];
	long double res = 1e18;
	rep(turn, 2) {
		swap(ax, bx);
		swap(ay, by);
		long double sum = 0;
		pair<long double, int> save[2];
		rep(i, 2)
			save[i].second = -1, save[i].first = 0;
		rep(i, n)
			sum += dis(make_pair(tx, ty), make_pair(px[i], py[i])) * 2;
		rep(i, n) {
			auto cur = make_pair(dis(make_pair(px[i], py[i]), make_pair(tx, ty)) - dis(make_pair(bx, by), make_pair(px[i], py[i])), i);
			if (cur > save[0])
				save[1] = save[0], save[0] = cur;
			else if (cur > save[1])
				save[1] = cur;
		}
		rep(i, n) {
			auto cur = dis(make_pair(px[i], py[i]), make_pair(tx, ty)) - dis(make_pair(ax, ay), make_pair(px[i], py[i]));
			long double cost = sum - cur - (save[0].second != i? save[0].first: save[1].first);
			res = min(res, cost);
		}
	}
	cout << setprecision(20) << fixed << res << endl;
	return 0;
}