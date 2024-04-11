#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll MOD = 1e9 + 7;

int q;
ll pw[MAXN], p_inv, P;
set<ll> len_st;
unordered_map<ll, int> hsh_st[MAXN];

int main() {
	P = rand() % MAXN;
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pw[i] = pw[i - 1] * P % MOD;

	cin >> q;
	while (q--) {
		int c;
		string s;
		cin >> c >> s;

		if (c == 1) {
			len_st.insert(s.size());
			ll hsh = 0;
			for (char c : s) 
				hsh = (hsh * P + (c - 'a')) % MOD;
			hsh_st[s.size()][hsh]++;
		} else if (c == 2) {
			ll hsh = 0;
			for (char c : s) 
				hsh = (hsh * P + (c - 'a')) % MOD;
			hsh_st[s.size()][hsh]--;
		} else {
			int ans = 0;
			for (int l : len_st) {
				ll hsh = 0;
				for (int i = 0; i < (int) s.size(); i++) {
					hsh = (hsh * P + s[i] - 'a') % MOD;	
					if (i >= l - 1) {
						if (i >= l) hsh = (hsh - pw[l] * (s[i - l] - 'a') % MOD + MOD) % MOD;
						ans += hsh_st[l][hsh];
					}
				} 
			}

			cout << ans << endl;
		}
	}
	return 0;
}