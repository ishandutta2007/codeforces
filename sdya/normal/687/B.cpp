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

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	long long g = 1;
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		g = lcm(g, v);
		g = gcd(g, k);
	}

	if (g % k == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}


	return 0;
}