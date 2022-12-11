#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	map<int, int> topCount;
	for (int i = 0; i < n; ++i) {
		int topic; scanf("%d", &topic);
		++topCount[topic];
	}
	vector<int> cts;
	for (auto tcpair : topCount) cts.push_back(tcpair.second);
	sort(cts.begin(), cts.end());
	int ans = 0;
	for (int i = 0; i < cts.size(); ++i) {
		int startElem = cts[i];
		for (int end = i; end < min(i+20, (int)cts.size()); ++end) {
			startElem = min(startElem, cts[end]/(1<<(end-i)));
			ans = max(ans, startElem*((1<<(end-i+1))-1));
		}
	}
	printf("%d\n", ans);
	return 0;
}