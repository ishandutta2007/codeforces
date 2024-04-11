#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	ll P, Q;
	cin >> P >> Q;
	const int to = 30000000;
	vi prime(to, 1), pal(to, 0);
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i < to; ++i) {
		if (!prime[i]) continue;
		for (int j = i*i; j < to; j += i)
			prime[j] = 0;
	}
	for (int dig = 1; dig <= 8; ++dig) {
		int ldig = (dig+1) / 2, p10 = 1;
		rep(i,0,ldig) p10 *= 10;
		rep(i,0,p10) {
			ostringstream oss;
			oss << setw(ldig) << setfill('0') << i;
			string s = oss.str(), s2 = s;
			// cout << s << endl; cin.get();
			reverse(all(s));
			if (s[0] == '0') continue;
			if (dig % 2 == 1) s.erase(s.end()-1);
			s += s2;
			istringstream iss(s);
			int num;
			iss >> num;
			if (num > 0 && num < to) pal[num] = 1;
		}
	}
	// rep(i,0,200) cout << i << ' ' << pal[i] << endl;

	int npr = 0, npal = 0;
	int res = 0;
	rep(i,1,to) {
		if (prime[i]) npr++;
		if (pal[i]) npal++;
		if (npr*Q <= P * npal)
			res = i;
	}
	cout << res << endl;
}