#include <cstdio>

const int MAXN = 110;
char str[MAXN];
int a, b;

typedef long long ll;

bool can(ll a, ll b, int c, int d) {
	if (d == 0) {
		if (b != 0) return false;
		if (c == 0) return a == 0;
		if (a % c != 0) return false;
		if (a / c < 0) return false;
		return true;
	}
	if (c == 0) {
		if (a != 0) return false;
		if (b % d != 0) return false;
		if (b / d < 0) return false;
		return true;
	}
	if (a % c != 0 || b % d != 0) return false;
	ll da = a / c;
	ll db = b / d;
	return da >= 0 && da == db;
}

bool go() {
	int x = 0, y = 0;
	scanf("%d %d", &a, &b);
	scanf("%s", str);
	for(int i = 0; str[i]; ++i) {
		if (str[i] == 'U') {
			++y;
		} else if (str[i] == 'D') {
			--y;
		} else if (str[i] == 'L') {
			--x;
		} else if (str[i] == 'R') {
			++x;
		}
	}
	int perx = x;
	int pery = y;
	x = 0;
	y = 0;
	for(int i = 0; str[i]; ++i) {
		ll dx = a - x;
		ll dy = b - y;

		if (can(dx, dy, perx, pery)) return true;

		if (str[i] == 'U') {
			++y;
		} else if (str[i] == 'D') {
			--y;
		} else if (str[i] == 'L') {
			--x;
		} else if (str[i] == 'R') {
			++x;
		}
	}
	return false;
}

int main() {
	if (go()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}