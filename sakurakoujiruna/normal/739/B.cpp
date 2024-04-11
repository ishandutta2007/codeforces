#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
using ll = long long;

ll a[N], w[N];
int p[N];

struct T {
	multiset <ll> s;
	ll os;
	void merge(T &t) {
		if(s.size() < t.s.size()) {
			s.swap(t.s);
			swap(os, t.os);
		}
		for(ll x : t.s)
			s.insert(x + t.os - os);
	}
	void pop() {
		while(s.size() && *s.begin() + os < 0)
			s.erase(s.begin());
	}
}t[N];

int ans[N];

vector <pair <int, int> > e[N];
void dfs(int x, int p = -1) {
	for(auto i : e[x]) {
		dfs(i.first, x);
		t[i.first].os -= i.second;
		t[x].merge(t[i.first]);
		t[i.first].s.clear();
	}
	t[x].pop();
	ans[x] = t[x].s.size() - 1;
}

int main() {
	ios :: sync_with_stdio(false);

	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		t[i].os = 0;
		t[i].s.insert(a[i]);
	}
	for(int i = 2; i <= n; i ++) {
		cin >> p[i] >> w[i];
		e[p[i]].push_back({i, w[i]});
	}
	dfs(1);

	/*
	for(int i = n; i >= 1; i --) {
		t[i].pop();
		ans[i] = t[i].s.size() - 1;
		if(i > 1) {
			t[i].os -= w[i];
			t[p[i]].merge(t[i]);
		}
	}
	*/
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}