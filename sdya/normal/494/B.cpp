#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 210000;
char s[maxN], t[maxN];

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

long long d[maxN], sum[maxN], h[maxN];
int pos[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	scanf("%s", &t);

	int n = strlen(s);
	int m = strlen(t);
	string x = t;
	x += '$';
	for (int i = 0; i < n; ++i) {
		x += s[i];
	}
	vector < int > p = prefix_function(x);

	vector < int > a(n + 1, 0);
	for (int i = m + 1; i <= m + n; ++i) {
		if (p[i] == m) {
			a[i - m] = 1;
		}
	}

	pos[0] = -1;
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			pos[i] = i - m;
		} else {
			pos[i] = pos[i - 1];
		}
	}

	d[0] = 1LL;
	sum[0] = 1LL;
	h[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		int j = pos[i];
		if (j >= 0) {
			d[i] += h[j];
			d[i] %= P;
		}
		sum[i] = d[i] + sum[i - 1];
		sum[i] %= P;
		h[i] = sum[i] + h[i - 1];
		h[i] %= P;
	}
	cout << ((sum[n] + P - 1) % P) << endl;

	return 0;
}