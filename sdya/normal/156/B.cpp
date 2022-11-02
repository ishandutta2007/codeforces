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
int n, m, a[maxN];
int killers[maxN], nonkillers[maxN];
int candidates[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > 0) {
			++killers[a[i]];
		} else {
			++nonkillers[-a[i]];
			++s;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int score = killers[i] + (s - nonkillers[i]);
		if (score == m) {
			candidates[i] = true;
			++cnt;
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool isT = false;
		bool isF = false;
		if (a[i] > 0) {
			if (candidates[a[i]]) {
				isT = true;
				if (cnt > 1) {
					isF = true;
				}
			} else {
				isF = true;
			}
		} else {
			if (!candidates[-a[i]]) {
				isT = true;
			} else {
				isF = true;
				if (cnt > 1) {
					isT = true;
				}
			}
		}
		if (isT && isF) {
			printf("Not defined\n");
		} else if (isT) {
			printf("Truth\n");
		} else {
			printf("Lie\n");
		}
	}


	return 0;
}