#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 300010
#define pli pair<ll, int>

int n;

set<pli> remos;
ll x[maxn];
ll y[maxn];
int bef[maxn];
int aft[maxn];

const ll inf = 1000000000LL;

ll dist(int u, int v) {
	return llabs(x[u]-x[v]) + llabs(y[u]-y[v]);
}

ll calc(int u) {
	return dist(bef[u], u) + dist(u, aft[u]) - dist(bef[u], aft[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		bef[i] = i-1;
		aft[i] = i+1;

	}
	aft[n] = 1;
	bef[1] = n;

	ll cperim = 0LL;

	for (int i = 1; i <= n; i++) {
		cperim += dist(i, aft[i]);
	}
	
	//get minimum y coordinate
	//get minimum x coordinate
	//get maximum x coordinate
	//get minimum y coorindate

	ll ans = 0;
	vector<int> minxp, minyp, maxxp, maxyp;
	ll minx = inf, maxx = -inf, miny = inf, maxy = -inf;

	for (int i = 1; i <= n; i++) {
		if (x[i] < minx) {
			minxp.clear();
			minx = x[i];
		}
		if (x[i] == minx) {
			minxp.push_back(i);
		}
		if (x[i] > maxx) {
			maxx = x[i];
			maxxp.clear();

		}
		if (x[i] == maxx) maxxp.push_back(i);

		if (y[i] < miny) {
			miny = y[i];
			minyp.clear();
		}
		if (y[i] == miny) minyp.push_back(i);
		if (y[i] > maxy) {
			maxy = y[i];
			maxyp.clear();
		}
		if (y[i] == maxy) maxyp.push_back(i);
	}

	vector<int> stuff;
	for (int v : minxp) stuff.push_back(v);
	for (int v : minyp) stuff.push_back(v);
	for (int v : maxxp) stuff.push_back(v);
	for (int v : maxyp) stuff.push_back(v);


	for (int u : stuff) {
		for (int v : stuff) {
			if (u >= v) continue;

			for (int i = 1; i <= n; i++) {
				if (i == u || i == v) continue;
				ans = max(ans, dist(u, i) + dist(u, v) + dist(v, i));
			}
		}
	}

	cout << ans << " ";
	for (int i = 4; i <= n; i++) {
		cout << cperim << " ";
	}

	cout << endl;
}