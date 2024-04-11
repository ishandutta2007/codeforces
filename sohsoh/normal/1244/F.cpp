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

const ll MAXN = 1e6 + 10;
const ll INF = 1e9 + 100;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string s;
int n, k, dist[2][MAXN];
queue<int> q[2];

inline int mkey(int k) {
	if (k < 0) k += n;
	if (k >= n) k -= n;
	return k;
}

inline void BFS(int ind) {
	while (!q[ind].empty()) {
		int v = q[ind].front();
		q[ind].pop();
		int u1 = mkey(v - 1), u2 = mkey(v + 1);
		if (dist[ind][u1] == INF) dist[ind][u1] = dist[ind][v] + 1, q[ind].push(u1);
		if (dist[ind][u2] == INF) dist[ind][u2] = dist[ind][v] + 1, q[ind].push(u2);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(dist[0], dist[0] + MAXN, INF);
	fill(dist[1], dist[1] + MAXN, INF);
		
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == s[mkey(i - 1)] || s[i] == s[mkey(i + 1)]) {
			if (s[i] == 'B') {
				dist[0][i] = 0;
				q[0].push(i);
			} else {
				dist[1][i] = 0;
				q[1].push(i);
			}
		}
	}
	
	BFS(0);
	BFS(1);

	for (int i = 0; i < n; i++) {
		if (min(dist[0][i], dist[1][i]) > k) {	
			if (k & 1) {
				if (s[i] == 'B') cout << 'W';
				else cout << 'B';
			} else cout << s[i];
		} else {
			if (dist[0][i] < dist[1][i]) cout << 'B';
			else if (dist[0][i] == dist[1][i]) {
				if (dist[0][i] & 1) cout << s[i];
				else {
					if (s[i] == 'B') cout << 'W';
					else cout << 'B';
				}
			}
			else cout << 'W';
		}
	}

	cout << endl;
	return 0;
}