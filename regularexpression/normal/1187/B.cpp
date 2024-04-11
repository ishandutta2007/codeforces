#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<random>
#include<functional>
#include<set>
#include<map>
#include<string>
#include<chrono>
#include<cassert>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, l, r) for (int i = (l); i < (r); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	int m;
	cin >> n >> s >> m;
	vector<vector<int>> c(26, vector<int>(n, 0));
	++c[s[0] - 'a'][0];
	forn(i, 26) {
		fore(j, 1, n) {
			c[i][j] = c[i][j - 1];
			if (s[j] - 'a' == i) {
				++c[i][j];
			}
		}
	}
	while (m--) {
		string t;
		cin >> t;
		vector<int> k(26, 0);
		forn(i, sz(t)) {
			++k[t[i] - 'a'];
		}
		int l = -1, r = n - 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			bool can = true;
			forn(i, 26) {
				can &= (c[i][mid] >= k[i]);
			}
			if (can) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r + 1 << '\n';
	}
	return 0;
}