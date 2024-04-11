/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 100 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[MAXN][MAXN], n;

ll ask(pll x, pll y) {
	if (x.X >= y.X && x.Y >= y.Y) swap(x, y);
	cout << '?' << sep << x.X << sep << x.Y << sep << y.X << sep << y.Y << endl;
	cout.flush();
	ll ans;
	cin >> ans;
	return ans;
}

void rev() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i % 2 != j % 2)
				G[i][j] = 1 - G[i][j];
}

void BFS(pll p) {
	queue<pll> q;
	q.push(p);
	while (!q.empty()) {
		ll x = q.front().X, y = q.front().Y;
		q.pop();
		if (x > 2 && G[x - 2][y] < 0) {
			ll ans = ask({x, y}, {x - 2, y});
			if (ans) G[x - 2][y] = G[x][y];
			else G[x - 2][y] = 1 - G[x][y];
			q.push({x - 2, y});
		}

		if (y > 2 && G[x][y - 2] < 0) {
			ll ans = ask({x, y}, {x, y - 2});
			if (ans) G[x][y - 2] = G[x][y];
			else G[x][y - 2] = 1 - G[x][y];
			q.push({x, y - 2});
		}

		if (x < n - 1 && G[x + 2][y] < 0) {
			ll ans = ask({x, y}, {x + 2, y});
			if (ans) G[x + 2][y] = G[x][y];
			else G[x + 2][y] = 1 - G[x][y];
			q.push({x + 2, y});
		}

		if (y < n - 1 && G[x][y + 2] < 0) {
			ll ans = ask({x, y}, {x, y + 2});
			if (ans) G[x][y + 2] = G[x][y];
			else G[x][y + 2] = 1 - G[x][y];
			q.push({x, y + 2});
		}

		if (x < n && y < n && G[x + 1][y + 1] < 0) {
			ll ans = ask({x, y}, {x + 1, y + 1});
			if (ans) G[x + 1][y + 1] = G[x][y];
			else G[x + 1][y + 1] = 1 - G[x][y];
			q.push({x + 1, y + 1});
		}

		if (x > 1 && y > 1 && G[x - 1][y - 1] < 0) {
			ll ans = ask({x, y}, {x - 1, y - 1});
			if (ans) G[x - 1][y - 1] = G[x][y];
			else G[x - 1][y - 1] = 1 - G[x][y];
			q.push({x - 1, y - 1});
		} 
	}
}

void print() {	
	cout << '!' << endl; cout.flush();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << G[i][j];
		cout << endl;
		cout.flush();
	}

	exit(0);
}

void dfs(pll v, vector<pll> vec = {}) {
	vector<pll> v2 = vec;
	v2.push_back(v);
	if (v2.size() == 4) {
		vector<ll> vm;
		ll x = 0;
		for (pll e : v2) {
			vm.push_back(G[e.X][e.Y]);
			x ^= vm.back();
		}	

		if (x == 0) {
			ll ans = 0;
			if (vm[0] == vm[3] && vm[1] == vm[2]) ans = 1;
			if (ans != ask(v2.front(), v2.back())) rev();
			print();
		}
	} else {
		if (v.X < n) dfs({v.X + 1, v.Y}, v2);
		if (v.Y < n) dfs({v.X, v.Y + 1}, v2);
	}
} 


int main() {
	cin >> n;
	for (int i = 0; i < n + 4; i++) for (int j = 0; j < n + 4; j++) G[i][j] = -1;
	G[1][1] = 1;
	G[1][2] = 0;
	G[n][n] = 0;
	BFS({1, 1});
	BFS({1, 2});

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dfs({i, j});
	
	//n = n / int(b);

	return 0;
}