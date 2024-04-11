#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<vector<ll>> dist(N, vector<ll>(N));
	rep(i,0,N) rep(j,i+1,N) {
		cin >> dist[i][j];
		dist[j][i] = dist[i][j];
	}
	ll inf = 1LL << 50;
	rep(i,0,N) dist[i][i] = inf;
	ll mi = 1LL << 60;
	rep(i,0,N) rep(j,i+1,N) {
		mi = min(mi, (ll)dist[i][j]);
	}

	vector<ll> dis(N, inf);

	int start = -2;
	rep(i,0,N) rep(j,0,N) if (i != j) {
		if (dist[i][j] == mi) {
			start = i;
			goto out;
		}
	}
out:;

	rep(i,0,N) rep(j,0,N) if (i != j) {
		dist[i][j] -= mi;
	}

	dis[start] = 0;
	rep(i,0,N) rep(j,0,N) if (i != j) {
		dis[j] = min(dis[j], 2*dist[i][j]);
	}

	vi done(N);
	rep(it,0,N) {
		pair<ll, int> best{inf+2, -2};
		rep(i,0,N) {
			if (!done[i]) best = min(best, {dis[i], i});
		}
		int at = best.second;
		done[at] = 1;
		rep(i,0,N) if (i != at) {
			dis[i] = min(dis[i], dis[at] + dist[at][i]);
		}
	}

	ll base = (N-1) * mi;
	rep(i,0,N) {
		cout << dis[i] + base << '\n';
	}
	exit(0);
}