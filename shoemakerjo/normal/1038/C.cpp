#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pli pair<ll, int>
priority_queue<pli> pq;
int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll cur;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		pq.push(pli(cur, 1));
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		pq.push(pli(cur, 2));
	}
	ll ans = 0LL;
	int mturn = 2;
	while (pq.size()) {
		if (mturn == 2) mturn = 1;
		else mturn = 2;

		pli tp = pq.top(); pq.pop();
		if (tp.second == mturn) {
			if (mturn == 2) ans -= tp.first;
			else ans += tp.first;
		}
	}
	cout << ans << endl;

}