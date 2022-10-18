#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vi isfort(N), bad(N), deg(N);
	vector<vi> ed(N);
	vi fort;
	rep(i,0,K) {
		int a;
		cin >> a;
		--a;
		fort.push_back(a);
		isfort[a] = 1;
	}
	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		ed[a].push_back(b);
		ed[b].push_back(a);
		deg[a]++;
		deg[b]++;
		if (isfort[a]) ++bad[b];
		if (isfort[b]) ++bad[a];
	}

	set<pair<double, int> > q;
	rep(i,0,N) {
		if (!isfort[i])
			q.insert(make_pair(-bad[i] / (double)deg[i], i));
	}

	pair<double, int> res(2, -1);
	while (!q.empty()) {
		auto pa = *q.begin();
		q.erase(q.begin());
		double badness = -pa.first;
		int ind = pa.second;
		res = min(res, make_pair(badness, sz(fort)));
		fort.push_back(ind);
		isfort[ind] = true;
		if (q.empty()) break;
		trav(ind2, ed[ind]) {
			if (isfort[ind2]) continue;
			q.erase(make_pair(-bad[ind2] / (double)deg[ind2], ind2));
			bad[ind2]++;
			q.insert(make_pair(-bad[ind2] / (double)deg[ind2], ind2));
		}
	}

	rep(i,0,N)
		isfort[i] = false;
	rep(i,0,res.second)
		isfort[fort[i]] = true;
	cout << N - res.second << endl;
	rep(i,0,N) {
		if (!isfort[i])
			cout << i+1 << ' ';
	}
	cout << endl;
}