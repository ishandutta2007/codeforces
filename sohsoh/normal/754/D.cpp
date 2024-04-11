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

int n, k, ans = 0, ans_l = int(2e9);
vector<pair<pll, int>> vec;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		vec.push_back({{l, r}, i});
	}
	
	sort(all(vec));
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto te : vec) {
		pll e = te.X;
		pq.push(e.Y);
		if (int(pq.size()) > k)
			pq.pop();

		int tans = pq.top() - e.X + 1;
		if (int(pq.size()) >= k && tans > ans) {
			ans = tans;
			ans_l = e.X;
		}
	}

	cout << ans << endl;
	vector<pll> tvec;

	for (auto e : vec)
		if (e.X.X <= ans_l) 
			tvec.push_back({e.X.Y, e.Y});

	sort(all(tvec), greater<pll>());
	for (int i = 0; i < k; i++)
		cout << tvec[i].Y + 1 << sep;
	cout << endl;
	return 0;
}