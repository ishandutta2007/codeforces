#include <bits/stdc++.h>

using namespace std;

void err_out() { cerr << endl; }
template<typename hd, typename... tl> void err_out(hd a, tl... b) { cerr << ' ' << a; err_out(b...); }
#ifdef LOCAL
#define err(...) cerr << "[" << #__VA_ARGS__ << "]:", err_out(__VA_ARGS__)
#else
#define err(...) 42
#endif

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

#define endl '\n'
using llint = long long;

#define MN 100005
typedef pair<int, int> pii;
vector<int> V[MN];
pii P[MN];
int cnt[MN];
int ans[MN];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	int Tc;
	for (cin >> Tc; Tc--;) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) cnt[i] = 0;
		for (int i = 0; i < m; i++) {
			V[i].clear();
			cin >> P[i].first;
			P[i].second = i;
			for (int j = 0; j < P[i].first; j++) {
				int f; cin >> f; f--;
				V[i].push_back(f);
			}
		}
		sort(P, P + m);
		bool flg = 0;
		for (int i = 0; i < m; i++) {
			int mn = (m + 1) / 2, id = -1;
			for (auto num : V[P[i].second]) {
				if (mn > cnt[num]) {
					mn = cnt[num];
					id = num;
				}
			}
			if (id == -1) {
				flg = 1;
				break;
			}
			ans[P[i].second] = id + 1;
			cnt[id]++;
		}
		if (flg) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (int i = 0; i < m; i++) cout << ans[i] << ' ';
			cout << endl;
		}
	}

	return 0;
}