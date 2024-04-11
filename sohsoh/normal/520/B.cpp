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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, dist[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(dist, dist + MAXN, INF);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (2 * v < MAXN && dist[2 * v] == INF) dist[2 * v] = dist[v] + 1, q.push(2 * v);
		if (v - 1 > 0 && dist[v - 1] == INF) dist[v - 1] = dist[v] + 1, q.push(v - 1);
	}

	cout << dist[m] << endl;
	return 0;
}