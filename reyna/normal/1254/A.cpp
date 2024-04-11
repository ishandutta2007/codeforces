
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 105, mod = (int) 0;
char s[N][N];
int a[N][N];
pair<int, int> seq[N * N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k, rices = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			for (int j = 0; j < m; ++j)
				rices += (s[i][j] == 'R');
		}
		int zero = (rices % k);
		int t = 0;
		for (int row = 0; row < n; row += 2) {
			for (int j = 0; j < m; ++j) seq[t++] = mp(row, j);
			if (row + 1 < n) for (int j = 0; j < m; ++j) seq[t++] = mp(row + 1, m - j - 1);
		}
		int h = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = k - 1;
		for (int cur = 0; cur < k; ++cur) {
			int x = seq[h].first, y = seq[h].second;
			int curc = 0;
			while (h < t && curc != ((rices / k) + (zero > 0))) {
				int cx = seq[h].first, cy = seq[h].second;
				a[cx][cy] = cur;
				++h;
				curc += (s[cx][cy] == 'R');
			}
			zero--;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int c = a[i][j];
				if (c < 10) {
					cout << (char) (c + '0');
				} else if (c < 36) {
					cout << (char) (c - 10 + 'a');
				} else {
					cout << (char) (c - 36 + 'A');
				}
			}
			cout << '\n';
		}
		
	}
}