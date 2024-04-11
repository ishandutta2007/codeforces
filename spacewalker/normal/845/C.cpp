#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, bool> evt;

int main() {
	int n; scanf("%d", &n);
	vector<evt> sched(2*n, make_pair(0, 0));
	for (int i = 0; i < n; ++i) {
		int li, ri; scanf("%d %d", &li, &ri);
		sched[2*i].first = li;
		sched[2*i].second = false;
		sched[2*i + 1].first = ri;
		sched[2*i + 1].second = true;
	}
	sort(sched.begin(), sched.end());
	int actives = 0;
	for (evt show : sched) {
		if (!show.second) { 
			++actives;
		} else {
			--actives;
		}
		if (actives > 2) {
			break;
		}
	}
	printf("%s", (actives > 0 ? "NO" : "YES"));
	return 0;
}