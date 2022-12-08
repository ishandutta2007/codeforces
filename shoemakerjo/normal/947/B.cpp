#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> ans;
	multiset<ll> piles;
	ll sum = 0LL;
	int N;
	cin >> N;
	ll v, t;
	ll vs[N];
	ll ts[N];
	for (int i = 0; i < N; i++) {
		cin >> vs[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> ts[i];
	}
	for (int i = 0; i < N; i++) {
		v = vs[i];
		t = ts[i];
		piles.insert(v+sum);
		sum += t;
		multiset<ll>::iterator it = piles.begin();
		ll cans = 0LL;
		while (it != piles.end()) {
			if (*it <= sum) {
				cans += t-(sum-*it);
				it = piles.erase(it);
			}
			else break;
		}
		cans += piles.size()*t;
		ans.push_back(cans);

	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> N;
	
}