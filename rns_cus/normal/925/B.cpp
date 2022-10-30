#include <bits/stdc++.h>
using namespace std;

#define N 300030
int n, x1, x2, c[N];

bool cmp(int i, int j) {return c[i] < c[j];}
int id[N];

vector<int> ans1, ans2;

bool func() {
	int good = -1;
	for (int i = n; i >= 1; i --) {
		if (1ll * c[i] * (n - i + 1) >= x1) {
			good = i;
			break;
		}
	}
	if (good < 0) return 0;
	for (int i = 1; i <= n; i ++) {
		int k = (x2 - 1) / c[i] + 1;
		if (i + k - 1 < good) {
			ans1.clear();
			ans2.clear();
			for (int j = good; j <= n; j ++) ans1.push_back(id[j]);
			for (int j = i; j <= i + k - 1; j ++) ans2.push_back(id[j]);
			return 1;
		}
	}
	return 0;
}

void print() {
	puts("Yes");
	printf("%d %d\n", ans1.size(), ans2.size());
	for (int x:ans1) printf("%d ", x);
	puts("");
	for (int x:ans2) printf("%d ", x);
	puts("");
}

int main() {
	scanf("%d%d%d", &n, &x1, &x2);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	sort(c + 1, c + n + 1);
	if (func()) {
		print();
		return 0;
	}
	swap(x1, x2);
	if (func()) {
		swap(ans1, ans2);
		print();
		return 0;
	}
	puts("No");
}