#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(ll i = 0; i < n; ++i)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		ll ans = 0;
		range(i, n) {
			if (b[i] == '0')
				continue;
			if (a[i] == '0')
				ans++;
			else if (i > 0 && a[i - 1] == '1') {
				ans++;
				a[i - 1] = '2';
			}
			else if (i < n - 1 && a[i + 1] == '1') {
				ans++;
				a[i + 1] = '2';
			}
		}
		cout << ans << "\n";
	}
	return 0;
}