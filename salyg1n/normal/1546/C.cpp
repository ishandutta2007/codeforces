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
		vector<int> a(n), b;
		input(a);
		b = a;
		sort(all(b));
		vector<int> chet1((int)1e5 + 1), chet2((int)1e5 + 1), nechet1((int)1e5 + 1), nechet2((int)1e5 + 1);
		range(i, n) {
			if (i % 2 == 0) {
				chet1[a[i]]++;
				chet2[b[i]]++;
			}
			else {
				nechet1[a[i]]++;
				nechet2[b[i]]++;
			}
		}
		if (chet1 == chet2 && nechet1 == nechet2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}