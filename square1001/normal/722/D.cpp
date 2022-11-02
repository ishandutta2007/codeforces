#include <set>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, a[50009], b[50009];
bool solve(int x) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		while (b[i] > x) b[i] >>= 1;
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (!s.count(b[i])) s.insert(b[i]);
		else {
			while (s.count(b[i])) b[i] >>= 1;
			s.insert(b[i]);
			if (b[i] == 0) return false;
		}
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = 1, r = 1000000009;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (solve(m)) r = m;
		else l = m;
	}
	if (n == 1) r = 1;
	while (!solve(r + 1)) r++;
	solve(r);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}