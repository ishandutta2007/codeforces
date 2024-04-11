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
	ll t;
	cin >> t;
	while (t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		if (b >= 0)
			cout << a * n + b * n << "\n";
		else {
			ll cnt = 1;
			FOR(i, 1, n - 1) {
				if (s[i] != s[i - 1])
					cnt++;
			}
			cout << ((cnt + 2) / 2) * b + a * n << "\n";
		}
	}
	return 0;
}