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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;


int n, A[MAXN], B[MAXN], C[MAXN], m, cnt[MAXN], cnt_p[MAXN], ind[MAXN];
vector<int> V[MAXN];

inline int solve() {
	for (int i = 0; i < max(n, m) + 10; i++) cnt[i] = 0, cnt_p[i] = 0, ind[i] = 0, V[i].clear();
	stack<int> pos;
	set<int> st;
		
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		if (A[i] != B[i]) cnt[B[i]]++, V[B[i]].push_back(i), st.insert(i);
		ind[B[i]] = i;
	}
	
	for (int i = 1; i <= m; i++) cin >> C[i], cnt_p[C[i]]++;
	for (int i = 1; i <= n; i++) if (ind[i] != 0 && cnt_p[i] > cnt[i]) pos.push(i); 
		
	vector<int> ans;
	for (int i = 1; i <= m; i++) {
		int c = C[i];
		cnt_p[c]--;

		if (!V[c].empty()) {
			int ind = V[c].back();
			V[c].pop_back();
			ans.push_back(ind);
			st.erase(ind);
			cnt[c]--;
			continue;
		}

		if (ind[c] != 0) {
			ans.push_back(ind[c]);
			st.erase(ind[c]);
			continue;
		}

		if (!st.empty()) {
			int t = *st.begin();;
			ans.push_back(t);
			continue;
		}

		bool flag = false;
		while (!pos.empty()) {
			int t = pos.top();
			pos.pop();
			if (cnt[t] < cnt_p[t] && ind[t] != 0) {
				cnt[t]++;
				st.insert(ind[t]);
				V[t].push_back(ind[t]);
				pos.push(t);
				flag = true;
				ans.push_back(ind[t]);
				break;
			}
		}

		if (!flag) return cout << "NO" << endl, 0;
	}

	if (!st.empty()) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}