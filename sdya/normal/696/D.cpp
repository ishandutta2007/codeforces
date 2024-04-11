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

const long long inf = 1000000000000000000LL;
typedef vector < vector < long long > > matrix;

matrix mul(const matrix& A, const matrix& B) {
	int n = A.size();
	matrix C(n, vector < long long > (n, -inf));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
			}
		}
	}
	return C;
}

const int maxN = 300;
int n;
long long L;
int a[maxN];
string s[maxN];

map < string, int > id;
vector < string > endings;
long long cost[maxN];
int m = 0;

int getId(const string &s) {
	if (id.count(s)) {
		return id[s];
	}
	endings.push_back(s);
	return id[s] = m++;
}

matrix A[60];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> L;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> s[i];

		for (int j = 0; j <= s[i].size(); ++j) {
			getId(s[i].substr(0, j));
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (endings[i].size() >= s[j].size() && endings[i].substr(endings[i].size() - s[j].size()) == s[j]) {
				cost[i] += a[j];
			}
		}
	}

	matrix cur(m, vector < long long > (m, -inf));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 26; ++j) {
			string s = endings[i];
			s += ('a' + j);

			int l = s.size();
			int index = -1;
			for (int k = l; k >= 0; --k) {
				if (id.count(s.substr(l - k))) {
					index = id[s.substr(l - k)];
					break;
				}
			}
			cur[i][index] = max(cur[i][index], cost[index]);
		}
	}

	A[0] = cur;
	for (int i = 1; i < 50; ++i) {
		A[i] = mul(A[i - 1], A[i - 1]);
	}

	int start = id[""];
	vector < long long > d(m, -inf);
	d[start] = 0;

	for (long long i = 0; i < 50; ++i) {
		if (L & (1LL << i)) {
			vector < long long > c(m, -inf);
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < m; ++k) {
					c[j] = max(c[j], d[k] + A[i][k][j]);
				}
			}
			d = c;
		}
	}

	long long res = *max_element(d.begin(), d.end());
	cout << res << endl;

	return 0;
}