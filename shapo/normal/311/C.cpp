#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <vector>

using namespace std;

#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long ll;
typedef pair < int, int > pii;

int k, n, m;
ll h;
vector < ll > pos, dist;
vector < int > val;
set < pii > cells;
vector < ll > shifts;

int recalc() {
	cells.clear();
	dist.assign(k, -1LL);
	dist[1] = 1LL;
	priority_queue < pair < ll, int > > q;
	q.push(make_pair(-dist[1], 1));
	while (!q.empty()) {
		pair < ll, int > cur = q.top();
		q.pop();
		if (dist[cur.second] < -cur.first)
			continue;
		foreach(i, shifts) {
			int go = (int) ((*i + cur.second) % k);
			if (dist[go] == -1 || dist[go] > (-cur.first + *i)) {
				dist[go] = (-cur.first + *i);
				q.push(make_pair(-dist[go], go));
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (val[i] != 0 && dist[pos[i] % k] != -1LL && dist[pos[i] % k] <= pos[i])
			cells.insert(make_pair(-val[i], i));
	return 0;
}

int decrease(int i, int dec) {
	pair < ll, int > corr = make_pair(-val[i], i);
	val[i] -= dec;
	if (cells.count(corr) != 0) {
		cells.erase(corr);
		cells.insert(make_pair(-val[i], i));
	}
	return 0;
}

int getMax() {
	if (cells.empty()) {
		cout << "0\n";
		return 0;
	}
	pii ans = *(cells.begin());
	cells.erase(ans);
	val[ans.second] = 0;
	cout << -ans.first << '\n';
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> h >> n >> m >> k;
	dist.resize(k);
	pos.resize(n);
	val.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> pos[i] >> val[i];
	recalc();
	for (int i = 0; i < m; ++i) {
		int type, x, y;
		ll hx;
		cin >> type;
		if (type == 3)
			getMax();
		else if (type == 2) {
			cin >> x >> y;
			decrease(x - 1, y);
		} else {
			cin >> hx;
			shifts.push_back(hx);
			recalc();
		}
	}
	return 0;
}