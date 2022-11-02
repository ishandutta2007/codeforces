#include <set>
#include <cstdio>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
int n, a[150009];
bool solve(int pos) {
	if (pos > 0) {
		if (pos % 2 == 0 && a[pos - 1] <= a[pos]) return false;
		if (pos % 2 == 1 && a[pos - 1] >= a[pos]) return false;
	}
	if (pos != n - 1) {
		if (pos % 2 == 0 && a[pos] >= a[pos + 1]) return false;
		if (pos % 2 == 1 && a[pos] <= a[pos + 1]) return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	vector<int> w;
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0 && a[i] >= a[i + 1]) w.push_back(i);
		if (i % 2 == 1 && a[i] <= a[i + 1]) w.push_back(i);
	}
	if (w.size() >= 5) puts("0");
	else {
		set<pair<int, int> > ret;
		for (int i = w[0]; i <= w[0] + 1; i++) {
			if (i >= n) continue;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				swap(a[i], a[j]);
				bool f = true;
				if (!solve(i)) f = false;
				if (!solve(j)) f = false;
				for (int k : w) {
					if (!solve(k)) f = false;
				}
				if (f) {
					if (i < j) ret.insert(make_pair(i, j));
					else ret.insert(make_pair(j, i));
				}
				swap(a[i], a[j]);
			}
		}
		printf("%d\n", (int)ret.size());
	}
	return 0;
}