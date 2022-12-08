#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<ll> waiting;
	priority_queue<ll> bought;
	priority_queue<ll> sold;
	ll ans = 0LL;
	ll cur;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		ll o1 = -1;
		if (sold.size() > 0 && 0-sold.top() < cur) {
			o1 = cur-(0-sold.top());
		}
		ll o2 = -1;
		if (waiting.size() > 0 && cur > 0-waiting.top()) {
			o2 = cur-(0-waiting.top());
		}
		
		if (o1 == -1 && o2 == -1) {
			waiting.push(0-cur);
			// cout << cur << " waited" << endl;
			continue;
		}
		if (o1 > o2) {
			ans += o1;
			// cout << cur << " sold it " << 0-sold.top() <<  endl;

			waiting.push(sold.top());
			sold.pop();
			sold.push(0-cur);
			continue;
		}
		else {
			ans += o2;
			// bought.push(0-waiting.top());
			// cout << cur << " sold a new one " << 0-waiting.top() << endl;
			waiting.pop();
			sold.push(0-cur);
			
			continue;
		}
	
	}
	cout << ans << endl;
	// cin >> N;
}