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

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	vector < int > a(n * n);
	multiset < int > s;
	for (int i = 0; i < n * n; ++i) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}

	vector < int > res;
	while (res.size() < n) {
		int value = *s.rbegin();
		res.push_back(value);
		s.erase(s.find(value));

		for (int i = 0; i + 1 < res.size(); ++i) {
			int g = gcd(res[i], value);
			s.erase(s.find(g));
			s.erase(s.find(g));
		}
	}

	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}