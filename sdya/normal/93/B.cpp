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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, w, m;
	cin >> n >> w >> m;
	vector < vector < int > > a(n, vector < int > (m));
	for (int i = 0; i < m; ++i) {
		for (int j = i * n; j < (i + 1) * n; ++j) {
			a[j / m][j % m] = i + 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		set < int > S;
		for (int j = 0; j < m; ++j) {
			S.insert(a[i][j]);
		}
		if (S.size() >= 3) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < n; ++j) {
			int cnt = count(a[j].begin(), a[j].end(), i);
			if (cnt > 0) {
				printf("%d %.10lf ", j + 1, (double)(cnt) / (double)(m) * (double)(w));
			}
		}
		printf("\n");
	}

	
	return 0;
}