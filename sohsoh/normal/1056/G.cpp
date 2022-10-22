//: // ////: ///  / : //// / :
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

const ll MAXN = 1e5 + 10;

unordered_map<int, ll> mp[MAXN];
ll n, m, s, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < MAXN; i++) mp[i].max_load_factor(0.25), mp[i].reserve(100);

	s--;
	while (t) {
		auto it = mp[t % n].find(s);
		if (it != mp[t % n].end()) {
			ll len = it -> Y - t;
			t %= len;
			break;
		}

		mp[t % n][s] = t;
		if (s < m) s = (s + t) % n;
		else s = ((s - t) % n + n) % n;
		t--;
	}

	while (t) {	
		if (s < m) s = (s + t) % n;
		else s = ((s - t) % n + n) % n;		
		t--;
	}

	cout << s + 1 << endl;
	return 0;
}