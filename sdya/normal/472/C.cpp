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

const int maxN = 110000;
const int maxL = 200;
int n;
char s[maxL];
string a[maxN], b[maxN];
int p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s);
		int m = strlen(s);
		for (int j = 0; j < m; ++j) {
			if (s[j] == ' ') {
				for (int k = j + 1; k < m; ++k) {
					b[i] += s[k];
				}
				break;
			} else {
				a[i] += s[j];
			}
		}
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}

	string cur = "";
	for (int i = 0; i < n; ++i) {
		if (a[p[i]] > cur) {
			cur = a[p[i]];
			continue;
		}
		if (b[p[i]] > cur) {
			cur = b[p[i]];
			continue;
		}
		printf("NO\n");
		return 0;
	}
	printf("YES\n");


	return 0;
}