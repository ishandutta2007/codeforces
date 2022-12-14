
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
string s[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cnt += (s[i][j] == 'A');
		if (cnt == n * m) {
			cout << 0 << '\n';
			continue;
		}
		if (cnt == 0) {
			cout << "MORTAL\n";
			continue;
		}
		cnt = 0;
		int is_one = 0, is_three = 0;
		for (int j = 0; j < n; ++j)
			cnt += (s[j][0] == 'A');
		is_one |= (cnt == n);
		is_three |= (cnt > 0);
		cnt = 0;
		for (int j = 0; j < n; ++j)
			cnt += (s[j][m - 1] == 'A');
		is_one |= (cnt == n);
		is_three |= (cnt > 0);
		cnt = 0;
		for (int j = 0; j < m; ++j)
			cnt += (s[0][j] == 'A');
		is_one |= (cnt == m);
		is_three |= (cnt > 0);
		cnt = 0;
		for (int j = 0; j < m; ++j)
			cnt += (s[n - 1][j] == 'A');
		is_one |= (cnt == m);
		is_three |= (cnt > 0);
		if (is_one) {
			cout << 1 << '\n';
			continue;
		}
		int is_two = 0;
		for (int row = 0; row < n; ++row) {
			int see = 0;
			for (int col = 0; col < m; ++col)
				see += (s[row][col] == 'A');
			is_two |= (see == m);
		}
		for (int col = 0; col < m; ++col) {
			int see = 0;
			for (int row = 0; row < n; ++row) {
				see += (s[row][col] == 'A');
			}
			is_two |= (see == n);
		}
		is_two |= (s[0][0] == 'A');
		is_two |= (s[0][m - 1] == 'A');
		is_two |= (s[n - 1][0] == 'A');
		is_two |= (s[n - 1][m - 1] == 'A');
		if (is_two) {
			cout << 2 << '\n';
			continue;
		}
		if (is_three) {
			cout << 3 << '\n';
			continue;
		}
		cout << 4 << '\n';
	}
}