
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

const int N = (int) 0, mod = (int) 0;
int cnt[256];
int main() {
	int q;
	cin >> q;
	while (q--) {
		memset(cnt, 0, sizeof cnt);
		string s, t, p;
		cin >> s >> t >> p;
		int n = (int) s.size(), m = (int) t.size();
		int pos = 0;
		for (int j = 0; j < m; ++j) {
			if (pos < n && s[pos] == t[j]) ++pos;	
		}
		if (pos != n) {
			cout << "NO\n";
			continue;
		}
		for (auto c : s) cnt[c]++;
		for (auto c : p) cnt[c]++;
		for (auto c : t) cnt[c]--;
		int sum = 0;
		for (int j = 0; j < 256; ++j)
			sum += (cnt[j] < 0);
		if (sum) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}