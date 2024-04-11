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

vector<pair<int, string>> vec[MAXN];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		int x, y;
		cin >> s >> x >> y;
		vec[x].push_back({y, s});
	}

	for (int i = 1; i <= m; i++) {
		sort(all(vec[i]), greater<pair<int, string>>());
		if (vec[i].size() <= 2 || vec[i][1].X != vec[i][2].X) {
			cout << vec[i][0].Y << sep << vec[i][1].Y << endl;
		} else cout << "?" << endl;
	}
	return 0;
}