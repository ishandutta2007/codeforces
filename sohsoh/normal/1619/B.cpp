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

inline int F(int a, int b) {
	int x = 0;
	while (true) {
		ll t = 1;
		for (int i = 0; i < b; i++)
			t *= x;
		if (t <= a) x++;
		else break;
	}

	return x - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		cout << F(x, 2) + F(x, 3) - F(x, 6) << endl;
	}
	return 0;
}