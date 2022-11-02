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

const int maxN = 1010000;
char s1[maxN], s2[maxN];
long long n, m;
long long a, b;

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

int cntA[maxN][26], cntB[maxN][26];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%I64d%I64d", &n, &m);
	scanf("%s", &s1);
	scanf("%s", &s2);

	a = strlen(s1);
	b = strlen(s2);

	long long d = gcd(a, b);
	long long cnt = (n * a) / lcm(a, b);

	for (int i = 0; i < a; ++i) {
		++cntA[i % d][s1[i] - 'a'];
	}
	for (int i = 0; i < b; ++i) {
		++cntB[i % d][s2[i] - 'a'];
	}

	long long res = lcm(a, b);
	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < 26; ++j) {
			res -= (long long)(cntA[i][j]) * (long long)(cntB[i][j]);
		}
	}
	res *= cnt;
	cout << res << endl;

	return 0;
}