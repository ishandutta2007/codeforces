#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
char s[maxN], t[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	scanf("%s", &t);

	int n = strlen(s);
	int d = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			++d;
		}
	}
	if (d % 2 != 0) {
		printf("impossible\n");
	} else {
		d /= 2;
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[i]) {
				printf("0");
			} else {
				if (d > 0) {
					printf("%c", s[i]);
					--d;
				} else {
					printf("%c", t[i]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}