#include <queue>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, b, t[200009], d[200009];
int main() {
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) scanf("%d %d", &t[i], &d[i]);
	queue<long long> que; long long tail = 0;
	for (int i = 0; i < n; i++) {
		while (!que.empty() && que.front() <= t[i]) que.pop();
		if (que.size() <= b) {
			if (tail < t[i]) tail = t[i]; tail += d[i];
			que.push(tail);
			printf("%lld ", tail);
		}
		else printf("-1 ");
	}
	return 0;
}