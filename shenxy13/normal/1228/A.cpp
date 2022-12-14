#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
bool is_unique(int N) {
	unordered_set<int> num;
	while (N != 0) {
		if (num.find(N % 10) != num.end()) return false;
		num.insert(N % 10);
		N /= 10;
	}
	return true;
}
int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	for (int i = l; i <= r; ++i) {
		if (is_unique(i)) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}