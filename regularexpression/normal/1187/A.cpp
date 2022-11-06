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
	int T;
	cin >> T;
	while (T--) {
		int n, s, t;
		cin >> n >> s >> t;
		int k = 0;
		if (s + t > n) {
			k = s + t - n;
		}
		s -= k;
		t -= k;
		cout << max(s, t) + 1 << '\n';
	}
	return 0;
}