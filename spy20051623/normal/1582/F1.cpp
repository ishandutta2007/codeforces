#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
int a[100005];
int d[10000];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(d, 63, sizeof d);
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		queue<int> q;
		for (int j = 0; j < 1024; ++j) {
			if (d[j] != inf && d[j] < a[i]) {
				q.push(j ^ a[i]);
			}
		}
		while (!q.empty()) {
			d[q.front()] = min(d[q.front()], a[i]);
			q.pop();
		}
	}
	int cnt = 0;
	for (int i = 0; i < 1024; ++i) {
		if (d[i] != inf) ++cnt;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 1024; ++i) {
		if (d[i] != inf) printf("%d ", i);
	}
	return 0;
}