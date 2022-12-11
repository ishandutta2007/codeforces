#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int digsum(int n) {
	if (n == 0) {
		return 0;
	} else {
		return (n % 10) + digsum(n/10);
	}
}

int f(int x) {
	return x + digsum(x);
}

int main() {
	int n; scanf("%d", &n);
	vector<int> res;
	for (int i = max(1, n-100); i <= n; ++i) {
		if (f(i) == n) {
			res.push_back(i);
		}
	}
	printf("%lu\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d\n", res[i]);
	}
}