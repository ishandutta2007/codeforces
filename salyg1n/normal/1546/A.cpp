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
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		input(a);
		input(b);
		int suma = 0, sumb = 0;
		range(i, n) {
			suma += a[i];
			sumb += b[i];
		}
		if (suma != sumb) {
			cout << -1 << "\n";
			continue;
		}
		vector<pair<int, int>> ans;
		while (a != b) {
			int i, j;
			range(k, n) {
				if (a[k] > b[k])
					i = k;
				if (a[k] < b[k])
					j = k;
			}
			ans.push_back({ i, j });
			a[i]--;
			a[j]++;
		}
			cout << ans.size() << "\n";
			for (auto i : ans)
				cout << i.first + 1<< " " << i.second + 1<< "\n";
		

	}
	return 0;
}