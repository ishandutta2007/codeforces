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

const int maxN = 1100000;
long long a[maxN];
int n;

long long gcd(long long a, long long b) {
	while (b) {
		long long q = a / b;
		a -= q * b;
		swap(a, b);
	}
	return a + b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
	}

	long long best = 1;
	for (int steps = 0; steps < 10; ++steps) {
		random_shuffle(a, a + n);
		unordered_map < long long, int > M;
		for (int i = 0; i < n; ++i) {
			++M[gcd(a[i], a[0])];
		}
		vector < pair < long long, int > > p;
		for (unordered_map < long long, int > ::iterator it = M.begin(); it != M.end(); ++it) {
			p.push_back(*it);
		}
		sort(p.begin(), p.end());
		for (int i = 0; i < p.size(); ++i) {
			int m = 0;
			for (int j = i; j < p.size(); ++j) {
				if (p[j].first % p[i].first == 0) {
					m += p[j].second;
				}
			}
			if (2 * m >= n) {
				best = max(best, p[i].first);
			}
		}
	}
	printf("%I64d\n", best);

	return 0;
}