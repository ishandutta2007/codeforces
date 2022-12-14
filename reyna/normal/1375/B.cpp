
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

const int N = (int) 305, mod = (int) 0;
int a[N][N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		int flag = 1;
		for (int i = 0; i < n && flag; ++i) {
			for (int j = 0; j < m && flag; ++j) {
				int cnt = 0;
				for (int a = -1; a <= 1; ++a)
					for (int b = -1; b <= 1; ++b) if (abs(a) + abs(b) == 1) {
						int x = i + a, y = j + b;
						if (x >= 0 && y >= 0 && x < n && y < m) {
							++cnt;
						}
					}
				if (cnt < a[i][j]) flag = 0;
				else a[i][j] = cnt;
			}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	
}