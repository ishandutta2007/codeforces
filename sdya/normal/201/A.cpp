#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int get(int s) {
	if (s % 2 == 0) {
		return (s * s) / 2;
	} else {
		return (s * s) / 2 + 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x;
	cin >> x;
	for (int i = 1; ;++i) {
		if (i % 2 == 0) {
			if (x % 4 != 0) {
				continue;
			}
			int y = get(i / 2 - 1);
			if (y >= x / 4) {
				printf("%d\n", i);
				return 0;
			}
		} else {
			int a = get(i / 2);
			int b = (i / 2) / 2;
			int c = 1;
			for (int u = 0; u <= a; ++u) {
				for (int v = 0; v <= b; ++v) {
					for (int w = 0; w <= b; ++ w) {
						for (int k = 0; k <= c; ++k) {
							if (u * 4 + (v + w) * 2 + k == x) {
								printf("%d\n", i);
								return 0;
							}
						}
					}
				}
			}

			if ((i / 2) % 2 == 1) {
				--a;
				++b;
				c = 0;
				for (int u = 0; u <= a; ++u) {
					for (int v = 0; v <= b; ++v) {
						for (int w = 0; w <= b; ++ w) {
							for (int k = 0; k <= c; ++k) {
								if (u * 4 + (v + w) * 2 + k == x) {
									printf("%d\n", i);
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}