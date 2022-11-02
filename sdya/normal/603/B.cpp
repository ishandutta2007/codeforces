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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 1100000;
int k, p;
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &p, &k);

	if (k == 0) {
		long long res = 1;
		for (int i = 1; i < p; ++i) {
			res = (res * p) % P;
		}
		printf("%d\n", (int)(res));
		return 0;
	}

	long long res = 1;
	for (int i = 1; i < p; ++i) {
		if (used[i]) {
			continue;
		}
		res = (res * p) % P;
		int j = i;
		while (!used[j]) {
			used[j] = true;
			j = ((long long)(j) * (long long)(k)) % (long long)(p);
		}
	}
	if (k == 1) {
		res = (res * p) % P;
	}

	printf("%d\n", (int)(res));

	return 0;
}