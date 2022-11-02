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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(11, 0), b(11, 3);
	b[0] = 4;
	for (int i = 0; i < 11; ++i) {
		int x = min(b[i], n);
		a[i] = x;
		n -= x;
	}

	printf("+------------------------+\n");
	for (int i = 0; i < 4; ++i) {
		printf("|");
		if (i != 2) {
			for (int j = 0; j < 11; ++j) {
				if (a[j] >= i + 1) {
					printf("O.");
				} else {
					printf("#.");
				}
			}
		} else {
			if (a[0] >= 3) {
				printf("O.");
			} else {
				printf("#.");
			}
			for (int j = 1; j < 11; ++j) {
				++a[j];
				printf("..");
			}
		}
		if (i == 0) {
			printf("|D|)");
		} else if (i == 1) {
			printf("|.|");
		} else if (i == 2) {
			printf("..|");
		} else {
			printf("|.|)");
		}
		printf("\n");
	}
	printf("+------------------------+\n");

	return 0;
}