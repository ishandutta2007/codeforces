#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

map < int, int > M;

int main() {
	int m, a, b, r0;
	scanf("%d%d%d%d", &a, &b, &m, &r0);
	M[r0] = 0;
	for (int i = 1; ; ++i) {
		r0 = (a * r0 + b) % m;
		if (M.count(r0) != 0) {
			printf("%d\n", i - M[r0]);
			return 0;
		}
		M[r0] = i;
	}
	return 0;
}