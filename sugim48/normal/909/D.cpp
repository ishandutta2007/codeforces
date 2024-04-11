#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	vector<pair<int, char>> st;
	string s; cin >> s;
	int N = s.length();
	vector<int> v;
	v.pb(0);
	rep(i, N - 1) if (s[i] != s[i + 1]) v.pb(i + 1);
	v.pb(N);
	for (int j = 0; j + 1 < v.size(); j++)
		st.pb({v[j + 1] - v[j], s[v[j]]});
	int ans = 0;
	while (st.size() > 1) {
		ans++;
		vector<pair<int, char>> _st;
		int M = st.size();
		rep(j, M) {
			int len = st[j].first;
			char c = st[j].second;
			int _len;
			if (j == 0 || j == M - 1) _len = len - 1;
			else _len = len - 2;
			if (_len > 0) _st.pb({_len, c});
		}
		st.clear();
		for (auto z: _st) {
			st.pb(z);
			int M = st.size();
			if (M >= 2 && st[M - 2].second == st[M - 1].second) {
				st[M - 2].first += st[M - 1].first;
				st.pop_back();
			}
		}
	}
	cout << ans << endl;
}