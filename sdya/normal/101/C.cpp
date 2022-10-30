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

bool check(long long a1, long long b1, long long a2, long long b2, long long a, long long b) {
	long long A1 = b1;
	long long B1 = -a1;
	long long C1 = a * b1 - b * a1;

	long long A2 = b2;
	long long B2 = -a2;
	long long C2 = a * b2 - b * a2;

	if (a1 == 0 && b1 == 0) {
		return a == 0 && b == 0;
	}

	double ya = (double)(C1) * (double)(b2) / (double)(A1 * a2 + B1 * b2);
	double xa = (double)(C1) * (double)(a2) / (double)(A1 * a2 + B1 * b2);

	if (a2 != 0) {
		xa /= (double)(a2);
	}
	if (b2 != 0) {
		ya /= (double)(b2);
	}

	long long u[2];
	u[0] = xa;
	u[1] = ya;

	double yb = (double)(C2) * (double)(b1) / (double)(A2 * a1 + B2 * b1);
	double xb = (double)(C2) * (double)(a1) / (double)(A2 * a1 + B2 * b1);

	if (a1 != 0) {
		xb /= (double)(a1);
	}
	if (b1 != 0) {
		yb /= (double)(b1);
	}

	long long v[2];
	v[0] = xb;
	v[1] = yb;
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (long long x = -2; x <= 2; ++x) {
				for (long long y = -2; y <= 2; ++y) {
					long long nx = (u[i] + x) * a2 + (v[j] + y) * a1;
					long long ny = (u[i] + x) * b2 + (v[j] + y) * b1;
					if (nx == a && ny == b) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a1, b1;
	long long a2, b2;
	long long a, b;
	cin >> a1 >> b1;
	cin >> a >> b;
	cin >> a2 >> b2;

	if (check(-b2, a2, a2, b2, a - a1, b - b1)
		|| check(-b2, a2, a2, b2, a - b1, b + a1)
		|| check(-b2, a2, a2, b2, a + a1, b + b1)
		|| check(-b2, a2, a2, b2, a + b1, b - a1)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}