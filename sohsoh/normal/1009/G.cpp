// Sohsoh84 :)))
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
const ll N = 6;

int cnt[N], F[1 << N], n, m;
string s, ans;
vector<int> v[MAXN];

inline void add(vector<int> v, int a) {
	int v_msk = 0;
	for (int e : v) v_msk ^= (1 << e);
	for (int msk = 0; msk < (1 << N); msk++)
		if (msk & v_msk)
			F[msk] += a;
}

inline bool hall() {
	for (int msk = 0; msk < (1 << N); msk++) {
		int c = 0;
		for (int i = 0; i < 6; i++)
			if (msk & (1 << i))
				c += cnt[i];
		if (c > F[msk]) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> m;
	n = s.size();
	for (char c : s) cnt[c - 'a']++;
	s = '.' + s;

	while (m--) {
		int i;
		string t;
		cin >> i >> t;
		for (char c : t) v[i].push_back(c - 'a');
	}

	for (int i = 1; i <= n; i++) {
		if (v[i].empty())
			for (int j = 0; j < N; j++)
				v[i].push_back(j);
		add(v[i], 1);
	}

	for (int i = 1; i <= n; i++) {
		add(v[i], -1);
		for (int j = 0; j < 6; j++) {
			if (cnt[j] && find(all(v[i]), j) != v[i].end()) {
				cnt[j]--;
				if (hall()) {
					ans.push_back(char(j + 'a'));
					break;
				}
				
				cnt[j]++;
			}
		}

		if (ans.size() != i) 
			return cout << "Impossible" << endl, 0;
	}
	
	cout << ans << endl;
	return 0;
}