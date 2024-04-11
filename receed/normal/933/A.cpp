// karelia18w-49 m8S9jYTTGG
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
#include <cstring>
#include <cassert>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0, ca;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> p(2, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i] - 1][i + 1]++;
		p[0][i + 1] += p[0][i];
		p[1][i + 1] += p[1][i];
	}
	for (int i = 0; i < n; i++) {
		int n1 = 0, n2 = 0;
		for (int j = i; j < n; j++) {
			if (a[j] == 2) {
				n2++;
				n1 = max(n1, n2);
			}
			else
				n1++;
			ans = max(ans, p[0][i] + n1 + p[1][n] - p[1][j + 1]);
		}
	}
	cout << ans;	
}