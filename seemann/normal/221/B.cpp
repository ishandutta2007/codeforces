#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;

const int INF = 1e9;
const int MAXD = 100;

int d[MAXD];
int c[MAXD];
int cd = 0;
int N;
int ans = 0;

void rec(int st, int cur) {
	if (st == cd) {
		char s1[20], s2[20];
		sprintf(s1, "%d", cur);
		int n1 = strlen(s1);
		sort(s1, s1 + n1);
		sprintf(s2, "%d", N);
		int n2 = strlen(s2);
		sort(s2, s2 + n2);
		int p1 = 0;
		int p2 = 0;
		bool ind = false;
		while (p1 < n1 && p2 < n2) {
			if (s1[p1] == s2[p2]) {
				ind = true;
				break;
			}
			if (s1[p1] < s2[p2])
				p1++;
			else
				p2++;
		}
		if (ind)
			ans++;
		return;
	}

	int w = cur;
	FOR(i, c[st] + 1) {
		rec(st + 1, w);
		w *= d[st];
	}
	return;
}


int main() {
	int n;
	cin >> n;
	N = n;
	for (int i = 2; i * i <= n; ++i) {
		bool ind = false;
		while (n % i == 0) {
			ind = true;
			n /= i;
			c[cd]++;
		}
		if (ind)
			d[cd++] = i;
	}
	if (n > 1) {
		d[cd] = n;
		c[cd++] = 1;
	}
	rec(0, 1);
	cout << ans;
	

	return 0;
}