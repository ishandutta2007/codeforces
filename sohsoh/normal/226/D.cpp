#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const ll MAXN = 100 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m;
int C[MAXN], R[MAXN], G[MAXN][MAXN];
bool CC[MAXN], CR[MAXN];
queue<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> G[i][j];
			R[i] += G[i][j];
			C[j] += G[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) if (R[i] < 0) st.push(i);
	for (int i = 1; i <= m; i++) if (C[i] < 0) st.push(MAXN + i);
	while (!st.empty()) {
		int x = st.front();
		st.pop();
		if (x < MAXN) {
			if (R[x] >= 0) continue;
			R[x] = -R[x];
			CR[x] = !CR[x];
			for (int j = 1; j <= m; j++) {
				C[j] += -2 * G[x][j];
				G[x][j] = -G[x][j];
				if (C[j] < 0) st.push(j + MAXN);	
			}
		} else {
			x -= MAXN;
			if (C[x] >= 0) continue;
			C[x] = -C[x];
			CC[x] = !CC[x];
			for (int i = 1; i <= n; i++) {
				R[i] += -2 * G[i][x];
				G[i][x] = -G[i][x];
				if (R[i] < 0) st.push(i);
			} 
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) if (CR[i]) ans.push_back(i);
	cout << ans.size() << sep;
	for (int e : ans) cout << e << sep;
	cout << endl;
	ans.clear();
	for (int j = 1; j <= m; j++) if (CC[j]) ans.push_back(j);
	cout << ans.size() << sep;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}