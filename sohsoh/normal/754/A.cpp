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

int n, ps[MAXN], ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ans[0] = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ps[i] = ps[i - 1] + x;
		ans[i] = 0;

		for (int j = 1; j <= i; j++)
			if (ans[j - 1] != 0 && ps[i] - ps[j - 1] != 0)
				ans[i] = j;
	}

	if (!ans[n]) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	
	vector<pll> vec;
	int x = n;
	while (x) {
		vec.push_back({ans[x], x});
		x = ans[x] - 1;
	}


	reverse(all(vec));
	cout << vec.size() << endl;
	for (pll e : vec)
		cout << e.X << sep << e.Y << endl;
	return 0;
}