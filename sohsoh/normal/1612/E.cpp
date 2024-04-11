#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;

int n, M[MAXN], K[MAXN], tans;
vector<int> F[MAXN];
pll fans = {0, 1};

inline bool cmp(pll a, pll b) {
	return a.X * b.Y < a.Y * b.X;
}

inline void calc() {
	cout << tans << endl;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int j = 1; j < MAXN; j++) {
		ll ans = 0;
		for (int e : F[j])
			ans += min(K[e], tans);

		pq.push({ans, j});

		if (pq.size() > tans) 
			pq.pop();
	}

	while (!pq.empty()) {
		cout << pq.top().Y << sep;
		pq.pop();
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> M[i] >> K[i], F[M[i]].push_back(i);

	vector<ll> vec;
	for (int i = 1; i <= 20; i++) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		ll s = 0;
		for (int j = 1; j < MAXN; j++) {	
			ll ans = 0, ts = 0;
			for (int e : F[j])
				ans += min(K[e], i), ts += K[e];

			s += ans;
			if (i == 1) vec.push_back(ts);
			pq.push(ans);

			if (pq.size() > i) 
				s -= pq.top(), pq.pop();	
		}

		if (cmp(fans, {s, i})) {
			fans = {s, i};
			tans = i;
		}
	}

	sort(all(vec));
	ll s = 0;
	for (int j = int(vec.size()) - 1; j > max(-1, int(vec.size()) - 20); j--)
		s += vec[j];

	for (int i = int(vec.size()) - 20; i >= 0; i--) {
		s += vec[i];
		if (cmp(fans, {s, vec.size() - i})) {
			fans = {s, vec.size() - i};
			tans = vec.size() - i;
		}
	}

	calc();
	return 0;
}