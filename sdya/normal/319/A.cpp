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

const long long P = 1000000007LL;
const int maxN = 2100;

long long p[maxN];
string s;

long long solve(int n) {
	if (n == 0) {
		return 0;
	}

	long long res = (2LL * solve(n - 1)) % P;
	if (s[n - 1] == '1') {
		res = (res + p[2 * (n - 1)]) % P;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p[i] = (p[i - 1] + p[i - 1]) % P;
	}
	cin >> s;
	reverse(s.begin(), s.end());

	cout << solve(s.size()) << endl;

	return 0;
}