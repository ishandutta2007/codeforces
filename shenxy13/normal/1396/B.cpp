#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, a, pre = 0;
		scanf("%d", &n);
		priority_queue<int> pq;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			pq.push(a);
		}
		for (int i = 0; i < 100000; ++i) {
			if (pq.empty()) {
				if (i % 2) printf("T\n");
				else printf("HL\n");
				break;
			}
			a = pq.top();
			pq.pop();
			if (pre != 0) pq.push(pre);
			pre = a - 1;
		}
	}
	return 0;
}