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

int n, A[MAXN], ans[MAXN], z;
vector<int> vec[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec[x % 3 * x % 3].push_back(i);
	}

	if (vec[0].size() > vec[1].size()) {
		z = 2;
		for (int i = 0; i < n / 2; i++) ans[vec[0][i]] = 1;
	} else {
		z = 0;
		for (int i = 0; i < n / 2; i++) ans[vec[1][i]] = 1;
	}

	cout << z << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i];
	cout << endl;

	return 0;
}