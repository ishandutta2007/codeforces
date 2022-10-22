// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int q, max_suff[MAXN], min_pref[MAXN];
string s;

vector<int> Calc(string s) {
	int n = s.size();
	vector<int> F(n, 0);
	int k = 0;

	for (int i = 1; i < n; i++) {
		while (k && s[k] != s[i])
			k = F[k - 1];
		k += (s[i] == s[k]);
		F[i] = k;
	}

	return F;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> q;
	int n = s.size(), m = 0;
	
	memset(min_pref, 63, sizeof min_pref);
	int ans = 0;
	while (q--) {	
		for (int i = 0; i < n + m + 10; i++) max_suff[i] = -1, min_pref[i] = INF; 
		
		string p;
		cin >> p;
		m = p.size();

		vector<int> v1 = Calc(p + "#" + s);
		reverse(all(p));
		reverse(all(s));
		vector<int> v2 = Calc(p + "#" + s);
		
		for (int i = m + 1; i < m + n + 1; i++) {
			max_suff[v2[i]] = max(m + n - i + v2[i], max_suff[v2[i]]);
			min_pref[v1[i]] = min(min_pref[v1[i]], i - m);
		}

		for (int i = n + m + 5; i >= 0; i--) {
			max_suff[i] = max(max_suff[i], max_suff[i + 1]);
			min_pref[i] = min(min_pref[i], min_pref[i + 1]);
		}

		bool flag = false;
		for (int i = 1; i < m; i++) {
			if (min_pref[i] < max_suff[m - i] - (m - i) + 1) {
				flag = true;
				break;
			}
		}

		ans += flag;
		reverse(all(s));
	}

	cout << ans << endl;
	return 0;
}