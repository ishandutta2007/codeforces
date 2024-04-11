#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void wt(int x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

int part(int x) {
	int ret = x;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int n;
vector <int> num;
#include <map>
map <int, bool> f;

int main() {
	scanf("%d", &n);
	for (int len = 1; len < 10; len ++) {
		for (int i = n; i >= n - len * 9; i --) {
			if (f[i] == 0 && part(i) == n) num.push_back(i), f[i] = 1;
		}
	}
	sort(num.begin(), num.end());
	wt(num.size()), putchar(10);
	for (int i = 0; i < num.size(); i ++) wt(num[i]), putchar(10);
	return 0;
}