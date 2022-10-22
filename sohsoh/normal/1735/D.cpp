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

const ll MAXN = 1e3 + 10;

int n, k;
map<ll, ll> mp;
vector<int> vec[MAXN];

inline ll f(vector<int> vec) {
	ll ans = 0;
	for (int e : vec)
		ans = ans * 3 + e;
	return ans;
}

inline vector<int> g(vector<int> a, vector<int> b) {
	vector<int> ans;
	for (int i = 0; i < k; i++)
		ans.push_back((6 - a[i] - b[i]) % 3);
	
	return ans;
}

inline ll C2(ll n) {
	return n * (n - 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			vec[i].push_back(x);
		}

		for (int j = 1; j < i; j++)
			mp[f(g(vec[i], vec[j]))]++;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += C2(mp[f(vec[i])]);

	cout << ans << endl;
	return 0;
}