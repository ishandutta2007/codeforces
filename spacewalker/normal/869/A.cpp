#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	set<int> total;
	vector<int> x(n, 0);
	vector<int> y(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		total.insert(x[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &y[i]);
		total.insert(y[i]);
	}

	int totalC = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (total.count(x[i] ^ y[j]) > 0) {
				++totalC;
			}
		}
	}
	printf("%s\n", (totalC % 2 == 0 ? "Karen" : "Koyomi"));
	return 0;
}