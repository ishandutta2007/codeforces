#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

inline void print(vector<int>& vec) {
	for (int e : vec)
		cout << e << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec;
		for (int i = 1; i <= n; i++) vec.push_back(n - i + 1);
		print(vec);

		for (int i = 0; i < n - 1; i++) {
			swap(vec[i], vec[i + 1]);
			print(vec);
			swap(vec[i], vec[i + 1]);
		}
	}
	return 0;
}