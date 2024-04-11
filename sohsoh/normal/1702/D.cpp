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

bool vis[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		int p;
		cin >> s >> p;

		int ans = 0;
		priority_queue<pair<int, int>> pq;	
		for (int i = 0; i < int(s.size()); i++) {
			vis[i] = true;
			ans += int(s[i] - 'a') + 1;
			pq.push({int(s[i] - 'a') + 1, i});
		}

		while (ans > p) {
			ans -= pq.top().X;
			vis[pq.top().Y] = false;
			pq.pop();
		}

		for (int i = 0; i < int(s.size()); i++)
			if (vis[i])
				cout << s[i];
		cout << endl;
	}
	return 0;
}