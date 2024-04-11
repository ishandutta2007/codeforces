//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 1e5 + 5;

int read() { int x; cin >> x; return x; }

int nxt[N][26], id[N], sz = 1, par[N];
string name[N];

void ins(string s, int cur) {
	int v = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		int ch = s[i] - 'a';
		if (ch < 0 || ch >= 26)
			ch += 'a' - 'A';
		if (!nxt[v][ch])
			nxt[v][ch] = sz++;
		v = nxt[v][ch];
	}
	id[v] = cur;
}

void call(int v) {
	if (v == 0)
		return;
	string s = name[par[v]];
	call(v - s.size());
	cout << s << ' ';
}


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(id, -1, sizeof id);
	memset(par, -1, sizeof par);
	int n;
	cin >> n;
	string t = "#", temp;
	cin >> temp;
	t += temp;
	n++;
	int m;
	cin >> m;
	rep(i, m) {
		cin >> name[i];
		ins(name[i], i);
	}
	par[0] = 0;
	rep(i, n) if (par[i] != -1) {
		int v = 0;
		int j = i + 1;
		while (j < n) {
			if (nxt[v][t[j] - 'a'])
				v = nxt[v][t[j] - 'a'];
			else
				break;
			if (id[v] != -1) {
				par[j] = id[v];
			}
			j++;
		}
	}
	call(n - 1);
}