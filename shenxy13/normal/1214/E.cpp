#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int d[100000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
	vector<int> x;
	for (int i = 0; i < n; ++i) x.push_back(i * 2 + 1);
	sort(x.begin(), x.end(), [=](const int &a, const int &b) {
		return d[a / 2] > d[b / 2];
	});
	for (int i = 0; i < n - 1; ++i) printf("%d %d\n", x[i], x[i + 1]);
	for (int i = 0; i < n; ++i) {
		int dx = d[x[i] / 2];
		if (i + dx == x.size()) {
			printf("%d %d\n", x.back(), x[i] + 1);
			x.push_back(x[i] + 1);
		} else printf("%d %d\n", x[i + dx - 1], x[i] + 1);
	}
	return 0;
}