#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int mx, my, w;
int r[maxN];
int a[maxN], b[maxN];

int rev(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}

int gcd(int x, int y) {
	if (x == 0 || y == 0) {
		return x + y;
	}
	if (x > y) {
		return gcd(x % y, y);
	} else {
		return gcd(y % x, x);
	}
}

map < pair < int, int >, vector < int > > MY;
map < pair < int, int >, vector < int > > MX;

long long getForX(int index, int bound) {
	vector < int > &current = MY[make_pair(b[index], a[index])];
	return upper_bound(current.begin(), current.end(), bound) - current.begin();
}

long long get(int mx, int bound) {
	long long res = 0;
	for (int i = 1; i <= mx; ++i) {
		res += getForX(i, bound);
	}
	return res;
}

long long getForY(int index, int bound) {
	vector < int > &current = MX[make_pair(a[index], b[index])];
	return upper_bound(current.begin(), current.end(), bound) - current.begin();
}

int calc(int mx) {
	int left_bound = 1, right_bound = my;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (get(mx, middle) >= w) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	if (get(mx, left_bound) >= w) {
		return left_bound;
	}
	if (get(mx, right_bound) >= w) {
		return right_bound;
	}
	return -1;
}

void trivial(int mx, int my, int w) {
	long long res = 1000000000000000000LL;
	int x = -1, y = -1;
	for (int i = 1; i <= mx; ++i) {
		for (int j = 1; j <= my; ++j) {
			int score = 0;
			for (int a = 1; a <= i; ++a) {
				for (int b = 1; b <= j; ++b) {
					if (a * b == r[a] * r[b]) {
						++score;
					}
				}
			}
			if (score >= w && i * j < res) {
				res = i * j;
				x = i;
				y = j;
			}
		}
	}
	cout << x << " " << y << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxN; ++i) {
		r[i] = rev(i);
	}

	cin >> mx >> my >> w;
	//trivial(mx, my, w);
	for (int i = 1; i <= max(mx, my); ++i) {
		a[i] = r[i];
		b[i] = i;
		int d = gcd(a[i], b[i]);
		a[i] /= d;
		b[i] /= d;
		MY[make_pair(a[i], b[i])].push_back(i);
		MX[make_pair(b[i], a[i])].push_back(i);
	}

	long long res = 1000000000000000000LL;
	int x = -1, y = -1;
	int currentY = calc(mx);

	if (currentY == -1) {
		cout << -1 << endl;
		return 0;
	}

	x = mx;
	y = currentY;
	res = (long long)(x) * (long long)(y);

	long long value = get(x, y);
	for (int i = mx - 1; i >= 1; --i) {
		value -= getForX(i + 1, currentY);
		while (currentY < my && value < w) {
			value += getForY(currentY + 1, i);
			++currentY;
		}
		if (value < w) {
			break;
		}
		if ((long long)(i) * (long long)(currentY) < res) {
			res = (long long)(i) * (long long)(currentY);
			x = i;
			y = currentY;
		}
	}

	cout << x << " " << y << endl;

	return 0;
}