#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 1000000007;

#define maxn 1000010
#define pii pair<ll, int>

int n, k;
ll a[maxn];

vector<vector<int>> inds(maxn);
ll modvals[maxn];
multiset<ll> curin;
ll myans[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		inds[i%(k-1)].push_back(i);
	}
	//compute modified values first
	for (int i = n-1; i >=0; i--) {
		curin.insert(a[i]);
		if (i + k < n) {
			curin.erase(curin.find(a[i+k]));
		}
		modvals[i] = *curin.rbegin();
	}

	int val;
	for (int i = 0; i < k-1; i++) {
		stack<pii> cur;
		for (int j = inds[i].size()-1; j >= 0; j--) {
			val = inds[i][j];

			ll cv = modvals[val];
			while (cur.size() && cv >= cur.top().first) {
				cur.pop();
			}
			if (cur.size()) {
				int indo = cur.top().second;
				ll ca = ((indo-j)*cv)%mod;
				ca = (ca + myans[inds[i][indo]]);
				myans[val] = ca;
			}
			else {
				ll nr = inds[i].size()-1-j;
				myans[val] = (nr*cv)%mod;
			}
			cur.push(pii(cv, j));
		}
	}

	ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		// cout << i << ": " << myans[i] << endl;
		ans = (ans + myans[i])%mod;
	}
	cout << ans << endl;
}