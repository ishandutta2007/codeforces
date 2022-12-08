#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n, m, q, len[N], tot, vis[N][N], active, ans;

int S(int n) { return n * (n + 1) / 2; }

struct Line {
	set<int> pt;
	void insert(int x) {
		set<int>::iterator it; int pre, suf;
		it = pt.lower_bound(x); suf = *it, --it, pre = *it;
		ans -= S(suf - pre - 1 - 1), pt.insert(x);
		ans += S(x - pre - 1 - 1) + S(suf - x - 1 - 1);
	}
	void erase(int x) {
		set<int>::iterator it; int pre, suf;
		it = pt.find(x); ++it, suf = *it, --it, --it, pre = *it;
		ans -= S(x - pre - 1 - 1) + S(suf - x - 1 - 1), pt.erase(x);
		ans += S(suf - pre - 1 - 1);
	}
} s[N];

vector<pair<int, int>> bel[N][N];

int init(int x, int y, int type, int step) {
	if(x > n || y > m) return 0;
	bel[x][y].push_back({ tot, step });
	if(type == 1) return init(x, y + 1, 0, step + 1) + 1;
	else return init(x + 1, y, 1, step + 1) + 1;
}

main() {
	n = get(), m = get(), q = get();
	for(int i = 1; i <= m; i++) {
		++tot, len[tot] = init(1, i, 1, 1);
		s[tot].pt.insert(0), s[tot].pt.insert(len[tot] + 1);
		ans += S(len[tot] - 1);
	}
	for(int i = 1; i <= n; i++) {
		++tot, len[tot] = init(i, 1, 0, 1);
		s[tot].pt.insert(0), s[tot].pt.insert(len[tot] + 1);
		ans += S(len[tot] - 1);
	}
	active = n * m;
	for(int i = 1; i <= q; i++) {
		int x = get(), y = get();
		if(vis[x][y]) {
			active++, vis[x][y] = 0;
			for(auto v : bel[x][y])
				s[v.first].erase(v.second);
		}
		else {
			active--, vis[x][y] = 1;
			for(auto v : bel[x][y])
				s[v.first].insert(v.second);
		}
		cout << ans + active << endl;
	}
	return 0;
}