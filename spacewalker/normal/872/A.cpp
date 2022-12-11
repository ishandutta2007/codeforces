#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> readSet(int n) {
	set<int> res;
	for (int i = 0; i < n; ++i) {
		int temp; scanf("%d", &temp);
		res.insert(temp);
	}
	return res;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	set<int> fs = readSet(n);
	set<int> ss = readSet(m);
	for (int i = 1; i < 10; ++i) {
		if (fs.count(i) > 0 && ss.count(i) > 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	for (int i = 10; i < 99; ++i) {
		int o = i % 10;
		int t = i / 10;
		if ((fs.count(o) > 0 && ss.count(t) > 0) || (fs.count(t) > 0 && ss.count(o) > 0)) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}