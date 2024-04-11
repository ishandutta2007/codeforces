#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unsigned long long H;

struct UF {
	vi e;
	UF(int n) {
		e.assign(n, -1);
	}
	bool same_set(int a, int b){ return (find(a)==find(b));}
	int size(int x) { return -e[find(x)]; }
	void join(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
	int find(int x) {
		if (e[x] < 0) return x;
		return e[x] = find(e[x]);
	}
};

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vi> ed[10];
	rep(i,0,10) ed[i].resize(N);
	UF uf(N);
	rep(i,0,M) {
		int a, b, len;
		cin >> a >> b >> len;
		ed[len][a].push_back(b);
		ed[len][b].push_back(a);
		if (len == 0) uf.join(a, b);
	}
	vi target(N);
	rep(i,0,N) target[i] = (uf.find(i) == uf.find(N-1));
	vi prev(N, -1), times(N);
	vi q = {0}, q2;
	prev[0] = -2; times[0] = -2;
	vector<H> ha(N);
	ha[0] = 1;
	while (!q.empty()) {
		bool only0 = false;
		trav(a, q) only0 = only0 || target[a];
		if (only0) {
			trav(v, q) if (target[v]) q2.push_back(v);
			q2.swap(q);
			q2.clear();
			while (ha[q.back()] != ha[q.front()]) {
				int v = q.back();
				prev[v] = -1;
				q.pop_back();
			}
		}
		rep(d,0,10) {
			if (only0 && d) break;
			trav(v, q) {
				trav(u, ed[d][v]) {
					if (prev[u] != -1) continue;
					ha[u] = ((ha[v] * 1123123917231LL) + d) ^ 129837102;
					prev[u] = v;
					times[u] = d;
					q2.push_back(u);
				}
			}
		}
		q2.swap(q);
		q2.clear();
	}

	int at = N-1;
	string timestr;
	vi visits;
	while (at != 0) {
		visits.push_back(at);
		int t = times[at];
		if (t || !timestr.empty()) timestr += (char)('0' + t);
		at = prev[at];
	}
	if (timestr.empty()) timestr = "0";
	cout << timestr << endl;
	cout << (sz(visits)+1) << endl;
	reverse(all(visits));
	cout << 0;
	trav(v, visits) cout << ' ' << v;
	cout << endl;
}