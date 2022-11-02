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

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
int mode[maxN], a[maxN], b[maxN];
int m;

int res[maxN];
int n;
long long p[maxN];
int v[maxN];

int getValue(long long position, long long length, int i) {
	if (mode[i] == 1) {
		return a[i];
	}
	position -= length + 1;
	position %= (long long)(a[i]);
	return v[position];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &mode[i], &a[i]);
		if (mode[i] == 2) {
			scanf("%d", &b[i]);
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &p[i]);
	}

	long long length = 0;
	int index = 0;
	int k = 0;
	for (int i = 0; i < m; ++i) {
		long long newLength = length;
		if (mode[i] == 1) {
			++newLength;
		} else {
			newLength += (long long)(a[i]) * (long long)(b[i]);
		}
		while (index < n && p[index] <= newLength) {
			printf("%d ", getValue(p[index], length, i));
			++index;
		}
		if (mode[i] == 1 && k < maxN) {
			v[k++] = a[i];
		} else {
			for (int j = 0; j < b[i] && k < maxN; ++j) {
				for (int l = 0; l < a[i] && k < maxN; ++l) {
					v[k++] = v[l];
				}
			}
		}
		length = newLength;
	}
	printf("\n");

	return 0;
}