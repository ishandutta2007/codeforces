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

int A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0, s = 0;

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i < n; i++) {
			cin >> A[i];
			if (A[i]) {
				s += A[i] - 1;
				ans += A[i] - 1;
				A[i] = 1;
			} else {
				if (s) {
					A[i] = 1;
					s--;
				} else pq.push(i);
			}
		}

		for (int i = 1; i < n; i++) {
			if (!A[i]) continue;
			while (!pq.empty() && pq.top() < i) pq.pop();
			if (!pq.empty()) {
				A[pq.top()] = 1;
				pq.pop();
			}

			ans++;
		}	

		cin >> s;
		cout << ans << endl;
	}
	return 0;
}