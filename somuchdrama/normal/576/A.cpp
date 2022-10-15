#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> ans;

int main() {    
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		bool pr = true;
		for (int j = 2; j * j <= i; ++j) {
			if (!(i % j)) {
				pr = false;
				break;
			}
		}
		int k = i;
		if (pr) 
			while (k <= n) {
				ans.pb(k);
				k *= i;
			}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
    return 0;
}