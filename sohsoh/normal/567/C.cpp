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

map<ll, ll> mp[2];
ll A[MAXN], n, k, ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	for (int i = n; i > 0; i--) {
		ans += mp[1][k * A[i]];
		mp[1][A[i]] += mp[0][k * A[i]];
		mp[0][A[i]]++;
	}

	cout << ans << endl;
	return 0;
}