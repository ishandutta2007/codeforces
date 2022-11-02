#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
const int N = 2e5L + 11;

int c[N];
int la[N], lb[N];

int main() {
	int n, m, k; cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++)
		scanf("%d", c + i);
	int a; cin >> a;
	for(int i = 0; i < a; i ++) {
		int x; scanf("%d", &x);
		la[x] = 1;
	}
	int b; cin >> b;
	for(int i = 0; i < b; i ++) {
		int x; scanf("%d", &x);
		lb[x] = 1;
	}
	vector <int> v[4];
	for(int i = 1; i <= n; i ++)
		v[la[i] + 2 * lb[i]].pb(c[i]);
	
	multiset <int> rb0, rb1; ll tmp = 0, sum = 0;
	
	auto add = [&](int x) {
		tmp += x;
		if(rb0.find(x) != rb0.end()) {
			sum -= x;
			rb0.erase(rb0.find(x));
		} else
			rb1.erase(rb1.find(x));
	};
	auto erase = [&](int x) {
		tmp -= x;
		if(x <= *rb1.begin()) {
			rb0.insert(x);
			sum += x;
		} else
			rb1.insert(x);
	};
	
	int c[4];
	for(int i = 0; i < 4; i ++) {
		c[i] = v[i].size();
		sort(v[i].begin(), v[i].end());
	}
	
	int use = min(c[3], k); 
	if(c[1] < k - use || c[2] < k - use || use + max(2 * (k - use), 0) > m) {
		cout << "-1\n";
		return 0;
	}
	
	for(int i = 0; i < c[3]; i ++)
		if(i >= use) {
			rb0.insert(v[3][i]); sum += v[3][i];
		} else
			tmp += v[3][i];
	for(int i = 0; i < c[2]; i ++)
		if(i >= k - use) {
			rb0.insert(v[2][i]); sum += v[2][i];
		} else
			tmp += v[2][i];
	for(int i = 0; i < c[1]; i ++)
		if(i >= k - use) {
			rb0.insert(v[1][i]); sum += v[1][i];
		} else
			tmp += v[1][i];
	for(int i : v[0]) {
		rb0.insert(i); sum += i;
	}
	
	ll ans = 1e18L;
	for(int i = use; i >= 0; i --) {
		if(c[1] < k - i || c[2] < k - i || i + max(2 * (k - i), 0) > m) break;
		if(i != use) {
			erase(v[3][i]); add(v[1][k - i - 1]); add(v[2][k - i - 1]);
		}
		int urb = m - (i + max(2 * (k - i), 0));
		if(rb0.size() + rb1.size() < urb) continue;
		while(rb0.size() < urb) {
			int x = *rb1.begin(); rb0.insert(x);
			sum += x; rb1.erase(rb1.begin());
		}
		while(rb0.size() > urb) {
			int x = *rb0.rbegin(); rb1.insert(x);
			sum -= x; rb0.erase(rb0.find(x));
		}
		ans = min(ans, tmp + sum);
	}
	cout << ans << '\n';
}