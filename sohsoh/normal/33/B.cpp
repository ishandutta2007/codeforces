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

const ll MAXN = 26 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dist[MAXN][MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t >> n;
	if (s.size() != t.size()) return cout << -1 << endl, 0;
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;
	for (int i = 0; i < MAXN; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++) {
		char a, b;
		int w;
		cin >> a >> b >> w;
		dist[int(a - 'a')][int(b - 'a')] = min(dist[int(a - 'a')][int(b - 'a')], w);
	}


	for (int k = 0; k < MAXN; k++)
		for (int u = 0; u < MAXN; u++) 
			for (int v = 0; v < MAXN; v++)
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
	int ans = 0;
	string ans_s;
	for (int i = 0; i < s.size(); i++) {
		int c1 = s[i] - 'a', c2 = t[i] - 'a';
		char ans_c = 'a';
		int tans = INF;
		for (int c = 0; c < 26; c++) {
			if (dist[c1][c] + dist[c2][c] < tans) {
				tans = dist[c1][c] + dist[c2][c];
				ans_c = char(c + 'a');
			}
		}
	
		if (tans == INF) return cout << -1 << endl, 0;
		ans += tans;
		ans_s.push_back(ans_c);
	}

	cout << ans << endl;
	cout << ans_s << endl;
	return 0;
}