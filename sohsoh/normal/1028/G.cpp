#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll, ll> pll;


#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXC = 1e4;
const ll INF = 1e18;

map<pll, ll> mp;
ll fc[10];

ll f(ll l, ll c) {
	if (mp.find(make_pair(l, c)) != mp.end()) return mp[make_pair(l, c)];
	if (c == 1) {
		ll k = min(MAXC, l);
		return mp[make_pair(l, c)] = l + k - 1;
	}

	if (l > MAXC) {
		return mp[make_pair(l, c)] = l + fc[c] - 1;
	}
	
	ll k = min(MAXC, l), r = f(l, c - 1);
	while (k--)
		r = f(r + 2, c - 1);

	return mp[make_pair(l, c)] = r;

}

inline ll ask(vector<int>& vec) {
	cout << int(vec.size()) - 1 << sep;
	for (int i = 1; i < int(vec.size()); i++)
		cout << vec[i] << sep;
	cout << endl;

	int i;
	cin >> i;
	if (i < 0) exit(0);
	if (i == 0) return vec[0];
	return vec[i] + 1;
}

void query(ll l, ll c) {
//	cerr << l << sep << c << sep << f(l, c) << endl;
	vector<int> tvec = {l};
	if (c == 1) {
		for (int i = l; i < l + min(MAXC, l); i++)
			tvec.push_back(i);
	} else if (l > MAXC) {
		int k = MAXC;
		for (int i = l + fc[c - 1]; k > 0; k--, i += fc[c - 1] + 1)
			tvec.push_back(i);
	} else {
		int k = l - 1;
		l = f(l, c - 1) + 1;
		tvec.push_back(l);

		while (k > 0) {
			k--;
			l = f(l + 1, c - 1) + 1;
			tvec.push_back(l);
		}
	}

	query(ask(tvec), c - 1);
}

int32_t main() {
	fc[1] = MAXC;
	for (int i = 2; i <= 5; i++)
		fc[i] = min(INF, MAXC * (fc[i - 1] + 1) + fc[i - 1]);
	query(1, 5);
	return 0;
}