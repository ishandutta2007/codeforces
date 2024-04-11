#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;

struct Queue {
	vector <int> a, b, mina;
	Queue() {}
	void push(int x) {
		a.push_back(x);
		if (!mina.size()) {
			mina.push_back(x);
		} else {
			mina.push_back(min(mina.back(), x));
		}
	}
	void pop() {
		if (!b.size()) {
			while (a.size()) {
				int x = a.back();
				a.pop_back();
				mina.pop_back();
				if (!b.size()) {
					b.push_back(x);
				} else {
					b.push_back(min(x, b.back()));
				}
			}
		}
		b.pop_back();
	}
	int top() {
		if (!b.size() && !mina.size()) {
			assert(false);
		}
		if (!b.size()) {
			return mina.back();
		} 
		if (!mina.size()) {
			return b.back();
		}
		return min(b.back(), mina.back());
	}
};

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	//ios_base::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector <vector <int> > data(n + 1, vector <int> (m, 0));
	int g0, x, y, z;
	cin >> g0 >> x >> y >> z;
	int nowg = g0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			data[i][j] = nowg;
			nowg = (nowg * (ll) x + (ll) y) % (ll) z;
		}
	}
	vector <Queue> q(m);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < a; i++) {
			q[j].push(data[i][j]);
		}
	}
	ll res = 0;
	Queue all;
	for (int j = 0; j < b; j++) {
		all.push(q[j].top());
	}
	for (int i = 0; i <= n - a; i++) {
		for (int j = 0; j < m; j++) {
			if (j <= m - b) {
				res += all.top();
				//cout << i << " " << j << " " << all.top() << "\n";
			}
			all.pop();
			all.push(q[(j + b) % m].top());
			q[j].pop();
			q[j].push(data[i + a][j]);
		}
	}
	cout << res << "\n";
}