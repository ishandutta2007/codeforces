
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
#define int long long
const int N = (int) 1e6 + 6;
int dp[26][26], cnt[26];
int32_t main() {
	string s;
	cin >> s;
	int n = (int) s.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		for (int c = 0; c < 26; ++c)
			dp[c][s[i]-'a'] += cnt[c];
		cnt[s[i]-'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		res = max(res, cnt[i]);
		for (int j = 0; j < 26; ++j)
			res = max(res, dp[i][j]);
	}
	cout << res << endl;
	
}