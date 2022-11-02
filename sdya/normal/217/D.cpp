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

const int maxN = 128;
const long long P = 1000000007LL;
int n, m, t;
int ways = 0;
int mx = 0;
int cnt[maxN];

void rec(int last, bitset <maxN> visited, long long coef = 1LL) {
	if (coef == 0) {
		return;
	}
	ways += coef;
	ways %= P;
	for (int i = last; 2 * i <= n && i < n; ++i) {
		if (visited[i]) {
			continue;
		}

		bitset<maxN> nvisited = visited;
		nvisited |= (visited << i);
		nvisited |= (visited >> (n - i));
		nvisited |= (visited << (n - i));
		nvisited |= (visited >> i);
		nvisited[i] = 1;
		nvisited[n - i] = 1;
		long long t = cnt[i] + cnt[n - i];
		if (i == n - i) {
			t -= cnt[i];
		}
		rec(i + 1, nvisited, (coef * t) % P);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> m >> n >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		cin >> x;
		++cnt[x % n];
	}
	bitset<maxN> current;
	rec(1, current);
	cout << ways << endl;

	return 0;
}