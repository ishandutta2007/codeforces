#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
int a[maxN];
int n;

const int maxD = 40;
int x[maxN], y[maxN];
int lenX, lenY;
double s[maxN];

const int maxS = 20;
int mx[maxS][maxN], nt[maxS][maxN];
int p[maxN];

void calculate(int index, double &res) {
	x[lenX] = n;
	for (int i = lenX; i >= 0; --i) {
		x[i] -= (i == 0 ? index : x[i - 1]);
	}
	y[lenY] = -1;
	for (int i = lenY; i >= 0; --i) {
		y[i] = (i == 0 ? index : y[i - 1]) - y[i];
	}

	double sX = 0, sY = 0;
	double p = 1.0;
	for (int i = 0; i <= lenX; ++i, p += p) {
		sX += (double)(x[i]) / p;
	}
	p = 1.0;
	for (int i = 0; i <= lenY; ++i, p += p) {
		sY += (double)(y[i]) / p;
	}
	res += (sX * sY) * ((double)(a[index]) / (double)(n + n));
}

int getMax(int l, int r) {
	int index = p[r - l + 1];
	return max(mx[index][l], mx[index][r - (1 << index) + 1]);
}

int getFirst(int index, int value) {
	if (getMax(index, n - 1) < value) {
		return -1;
	}
	int left_bound = index, right_bound = n - 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (getMax(index, middle) >= value) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	if (getMax(index, left_bound) >= value) {
		return left_bound;
	}
	return right_bound;
}

int getLast(int index, int value) {
	if (getMax(0, index) < value) {
		return -1;
	}
	int left_bound = 0, right_bound = index;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (getMax(middle, index) >= value) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}
	if (getMax(right_bound, index) >= value) {
		return right_bound;
	}
	return left_bound;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	/*n = 300000;
	for (int i = 0; i < n; ++i) {
		a[i] = rand() + 1;
	}*/

	for (int i = 0; i < n; ++i) {
		mx[0][i] = a[i];
		nt[0][i] = i + 1;
	}
	nt[0][n] = n;
	mx[0][n] = 0;
	for (int i = 1; i < maxS; ++i) {
		nt[i][n] = n;
		mx[i][n] = 0;
		for (int j = 0; j < n; ++j) {
			nt[i][j] = nt[i - 1][nt[i - 1][j]];
			mx[i][j] = max(mx[i - 1][nt[i - 1][j]], mx[i - 1][j]);
		}
	}
	for (int i = 1; i < maxN; ++i) {
		int j = 1, k = 0;
		while (j + j <= i) {
			j += j;
			++k;
		}
		p[i] = k;
	}
	/*double ans = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			vector < int > b(j - i + 1);
			for (int k = i; k <= j; ++k) {
				b[k - i] = a[k];
			}
			sort(b.rbegin(), b.rend());
			double p = 1.0;
			for (int k = 0; k < b.size(); ++k, p += p) {
				s[k + i] += (double)(b[k]) / p;
			}
		}
	}*/
	double res = 0.0;
	for (int i = 0; i < n; ++i) {
		lenX = 0;
		int index = i;
		while (lenX < maxD && index + 1 < n) {
			index = getFirst(index + 1, a[i]);
			if (index == -1) {
				break;
			}
			x[lenX++] = index;
		}

		index = i;
		lenY = 0;
		while (lenY < maxD && index - 1 >= 0) {
			index = getLast(index - 1, a[i] + 1);
			if (index == -1) {
				break;
			}
			y[lenY++] = index;
		}
		calculate(i, res);
		if (i % 1000 == 0) {
			cerr << i << endl;
		}
	}
	printf("%.10lf\n", res / (double)(n));

	//cerr << clock() << endl;

	
	/*for (int i = 0; i < n; ++i) {
		ans += s[i];
	}
	ans /= (double)(2 * n * n);
	printf("%.10lf\n", ans);*/

	return 0;
}