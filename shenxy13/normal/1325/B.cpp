#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, a;
		scanf("%d", &n);
		set<int> ele;
		for (int j = 0; j < n; ++j) scanf("%d", &a), ele.insert(a);
		printf("%lu\n", ele.size());
	}
	return 0;
}