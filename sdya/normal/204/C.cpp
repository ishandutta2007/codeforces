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

const int maxN = 210000;
int n;
char a[maxN], b[maxN];
vector < int > x[26], y[26];
vector < double > s;

double getSum(int l, int r) {
	if (l > r) {
		return 0;
	}
	return s[r] - (l == 0 ? 0 : s[l - 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", &a);
	scanf("%s", &b);
	for (int i = 0; i < n; ++i) {
		x[a[i] - 'A'].push_back(i);
		y[b[i] - 'A'].push_back(i);
	}

	long long total = 0;
	for (int i = 1; i <= n; ++i) {
		total += (long long)(i) * (long long)(i);
	}

	double res = 0;
	for (int i = 0; i < 26; ++i) {
		int m = y[i].size();
		if (m == 0) {
			continue;
		}

		s.assign(m, 0);
		for (int j = 0; j < m; ++j) {
			s[j] = y[i][j];
			if (j > 0) {
				s[j] += s[j - 1];
			}
		}

		int index = 0;
		for (int j = 0; j < x[i].size(); ++j) {
			while (index < y[i].size() && y[i][index] < x[i][j]) {
				++index;
			}

			{
				double coef = m - index;
				res += (double)(x[i][j] + 1) * (coef * (double)(n) - getSum(index, m - 1));
			}
			{
				double coef = index;
				res += (double)(n - x[i][j]) * (getSum(0, index - 1) + coef);
			}
		}
	}

	double p = (double)(res) / (double)(total);
	printf("%.10lf\n", p);

	return 0;
}