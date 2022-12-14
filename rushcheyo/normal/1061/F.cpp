#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

int n, k;

int power(int a, int x) { int res = 1; while (x--) res *= a; return res; }
bool query(int a, int b, int c) {
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	char op[10];
	scanf("%s", op);
	return op[0] == 'Y';
}

bool check(int leaf) {
	int x = leaf == 1 ? 2 : 1;
	for (int y = 1; y <= n; ++y)
		if (y != x && y != leaf && query(x, leaf, y))
			return false;
	return true;
}
vector<int> path;
bool check(int h, int x, int y) {
	path.clear();
	for (int i = 1; i <= n; ++i)
		if (i == x || i == y || query(x, i, y))
			path.push_back(i);
	return path.size() == 2 * h + 1;
}

int main() {
	scanf("%d%d", &n, &k);
	int sum = 1, h = 0;
	while (sum != n)
		++h, sum += power(k, h);
	int x;
	do x = gen(1, n);
	while (!check(x));
	int y;
	do y = gen(1, n);
	while (!check(y) || !check(h, x, y));
	nth_element(path.begin(), path.begin() + h, path.end(), [x](int a, int b) { return a == b ? false : query(x, a, b); });
	printf("! %d\n", path[h]);
	fflush(stdout);
	return 0;
}