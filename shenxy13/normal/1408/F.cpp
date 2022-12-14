#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
typedef pair<int, int> ii;
deque<ii> ops;
int logtwo(int x) {
	int ans = 0;
	while (x != 1) x >>= 1, ++ans;
	return ans;
}
void dnc(int a, int b) {
	if (a == b) return;
	int k = logtwo(b - a + 1);
	if (b - a + 1 == (1 << k)) {
		dnc(a, a + (b - a) / 2);
		dnc(b - (b - a) / 2, b);
		for (int i = a; i - a < b - i; ++i) ops.push_back(ii(i, a + b - i));
		return;
	}
	deque<int> dcmp[14];
	int ptr = a;
	for (int j = b; j > b - (1 << k); --j) dcmp[k].push_back(j);
	reverse(dcmp[k].begin(), dcmp[k].end());
	for (int i = k - 1; i >= 0; --i) {
		if (ptr + (1 << i) <= dcmp[k].front()) {
			for (int j = ptr; j < ptr + (1 << i); ++j) dcmp[i].push_back(j);
			ptr += 1 << i;
		}
	}
	dnc(a, dcmp[k].front() - 1);
	dnc(dcmp[k].front(), b);
	for (int i = 0; i < k; ++i) {
		if ((i == 0 || dcmp[i - 1].empty()) && dcmp[i].empty()) continue;
		if (dcmp[i].empty()) {
			for (int j: dcmp[i - 1]) dcmp[i].push_back(j);
			dcmp[i - 1].clear();
		}
		if (i == 0 || dcmp[i - 1].empty()) {
			deque<int> steal;
			for (int j = 0; j < dcmp[i].size(); ++j) steal.push_back(dcmp[k].front()), dcmp[k].pop_front();
			for (int j = 0; j < steal.size(); ++j) ops.push_back(ii(dcmp[i][j], steal[j])), dcmp[i].push_back(steal[j]);
		} else {
			for (int j = 0; j < dcmp[i - 1].size(); ++j) ops.push_back(ii(dcmp[i][j], dcmp[i - 1][j])), dcmp[i].push_back(dcmp[i - 1][j]);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	dnc(1, n);
	printf("%lu\n", ops.size());
	for (ii i: ops) printf("%d %d\n", i.first, i.second);
	return 0;
}