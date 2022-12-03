#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int main() {
	string s, p; cin >> s >> p;
	int S = s.length(), P = p.length();
	vector< vector<int> > dp(S + 1, vector<int>(S + 1, INT_MAX / 2));
	for (int i = 0; i <= S; i++) dp[i][0] = 0;
	for (int i = 1; i <= S; i++)
		for (int j = 1; j <= S; j++) {
			if (s[i - 1] == p[(j + P - 1) % P]) dp[i][j] = dp[i - 1][j - 1];
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + (j % P == 0 ? 0 : 1));
		}
	vector<int> a(S + 1);
	for (int i = 0; i <= S; i++)
		for (int j = 0; j <= S; j++) {
			int x = dp[i][j];
			if (x == INT_MAX / 2) continue;
			a[x] = max(a[x], j / P);
		}
	for (int x = 1; x <= S; x++)
		a[x] = max(a[x], a[x - 1]);
	for (int x = 0; x <= S; x++)
		a[x] = min(a[x], (S - x) / P);
	for (int x = 0; x <= S; x++)
		cout << a[x] << ' ';
	cout << endl;
}