#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int h, m;
		scanf("%d %d", &h, &m);
		printf("%d\n", (23 - h) * 60 + (60 - m));
	}
	return 0;
}