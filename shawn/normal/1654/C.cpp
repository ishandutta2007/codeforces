#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue <ll, vector<ll>, less<ll> > p, q;

ll sum, _, n;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		cin >> n;
		for (int a, i = 1; i <= n; i ++) 
			cin >> a, sum += a, p.push(a);
		q.push(sum);
		while (!q.empty() && !p.empty()) {
			ll u = q.top(); q.pop();
			ll v = p.top(); p.pop();
			// cerr << u << " " << v << "\n";
			if (u == v) continue;
			else if (u > v) {
				q.push(u / 2), q.push(u - u / 2);
				p.push(v);
			}
			else break;
		}
		if (q.empty() && p.empty()) cout << "YES\n";
		else cout << "NO\n";
		while (!q.empty()) q.pop();
		while (!p.empty()) p.pop();
		sum = 0;
	} 
	return 0;	
}