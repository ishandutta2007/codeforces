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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> vec;
		int n;
		cin >> n;
		while (n > 0) {
			if (n > 1) {
				if (vec.empty() || vec.back() == 1) {
					vec.push_back(2);
					n -= 2;
				} else {
					vec.push_back(1);
					n -= 1;
				}
			} if (n == 1) {
				if (vec.empty() || vec.back() == 1) {
					vec.insert(vec.begin(), 1);
				} else vec.push_back(1);
				n--;
			}
		}

		for (int e : vec)
			cout << e;
		cout << endl;
	}
	return 0;
}