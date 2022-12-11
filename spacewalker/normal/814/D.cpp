#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define NINF
using namespace std;

struct Dancer {
	int x;
	int y;
	int r;
	Dancer(int xi, int yi, int rad) : x(xi), y(yi), r(rad) {}
};

bool inside(Dancer a, Dancer b) {
	return (hypot(a.x - b.x, a.y - b.y) <= b.r - a.r);
}

double area(Dancer d) {
	return 3.1415926535897 * d.r * d.r;
}

const bool operator < (const Dancer a, const Dancer b) {
	return (a.r < b.r);
}

int main() {
	int n; scanf("%d", &n);
	vector<Dancer> disco(n, Dancer(0, 0, 0));
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &(disco[i].x), &(disco[i].y), &(disco[i].r));
	}

	vector<vector<int>> childTable(n, vector<int>());
	vector<bool> isHead(n, true);

	sort(disco.begin(), disco.end());

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (inside(disco[j], disco[i]) && j != i && isHead[j]) {
				childTable[i].push_back(j);
				isHead[j] = false;
			}
		}
	}

	queue<int> q;
	vector<int> travelOrder;
	for (int i = 0; i < n; ++i) {
		if (isHead[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		travelOrder.push_back(cur);
		for (int child : childTable[cur]) {
			q.push(child);
		}
	}

	reverse(travelOrder.begin(), travelOrder.end());

	vector<double> aobo(n, 0);
	vector<double> aebo(n, 0);
	vector<double> aobe(n, 0);
	vector<double> aebe(n, 0);

	for (int i : travelOrder) {
		if (childTable[i].size() == 0) {
			aobo[i] = -area(disco[i]);
			aobe[i] = aebe[i] = aebo[i] = area(disco[i]);
		} else {
			double aobes = 0;
			double aebos = 0;
			double aobos = 0;
			double aebes = 0;
			for (int child : childTable[i]) {
				aobes += aobe[child];
				aebos += aebo[child];
				aobos += aobo[child];
				aebes += aebe[child];
			}

			aobo[i] = max(aebos, aobes) - area(disco[i]);
			aebo[i] = max(aobos + area(disco[i]), aebes - area(disco[i]));
			aebe[i] = max(aobes, aebos) + area(disco[i]);
			aobe[i] = max(aebes - area(disco[i]), aobos + area(disco[i]));
		}
	}

	double total = 0;
	for (int i = 0; i < n; ++i) {
		if (isHead[i]) {
			total += aebe[i];
		}
	}

	printf("%.10f\n", total);

	return 0;
}