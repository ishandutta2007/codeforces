
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

const int N = (int) 1e6 + 6, mod = (int) 0;
int cnt[26], fst[26][N];
int main() {
	memset(fst, 63, sizeof fst);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int c = 0; c < 26; ++c) fst[c][0] = 0;
	for (int j = 0; j < (int) s.size(); ++j) {
		cnt[s[j] - 'a']++;
		fst[s[j] - 'a'][cnt[s[j] - 'a']] = j + 1;
	}
	memset(cnt, 0, sizeof cnt);
	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		memset(cnt, 0, sizeof cnt);
		for (auto c : t) cnt[c - 'a']++;
		int res = 0;
		for (int c = 0; c < 26; ++c) {
			res = max(res, fst[c][cnt[c]]);
		}
		cout << res << '\n';
	}
}