#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000003LL;
int n, m;
vector < string > s;

long long solve(vector < int > a) {
	int n = a.size();
	vector < vector < long long > > d(n, vector < long long > (2, 0));
	if (a[0] & 1) {
		++d[0][0];
	}
	if (a[0] & 2) {
		++d[0][1];
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] & 1) {
			d[i][0] += d[i - 1][1];
		}
		if (a[i] & 2) {
			d[i][1] += d[i - 1][0];
		}
		d[i][0] %= P;
		d[i][1] %= P;
	}
	return (d[n - 1][0] + d[n - 1][1]) % P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	s.assign(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	long long res = 1LL;
	for (int i = 0; i < n; ++i) {
		vector < int > current(m);
		for (int j = 0; j < m; ++j) {
			current[j] = 3;
			if (s[i][j] == '1' || s[i][j] == '2') {
				current[j] = 1;
			} 
			if (s[i][j] == '3' || s[i][j] == '4') {
				current[j] = 2;
			}
		}
		res *= solve(current);
		res %= P;
	}
	for (int j = 0; j < m; ++j) {
		vector < int > current(n);
		for (int i = 0; i < n; ++i) {
			current[i] = 3;
			if (s[i][j] == '1' || s[i][j] == '4') {
				current[i] = 1;
			}
			if (s[i][j] == '2' || s[i][j] == '3') {
				current[i] = 2;
			}
		}
		res *= solve(current);
		res %= P;
	}

	cout << res << endl;
	return 0;
}