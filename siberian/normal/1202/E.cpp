#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

struct Node{
	unordered_map<char, int> nxt, go;
	char pc;
	int suffLink, par, term;
	bool findTerm;
	Node() : nxt(), go(), pc('-'), suffLink(-1), par(-1), term(0), findTerm(false) {}
};

vector<Node> trie;

void addString(const string& s) {
	int now = 0;
	for (const char c : s) {
		if (trie[now].nxt.find(c) == trie[now].nxt.end()) {
			int nxt = trie.size();
			trie.push_back(Node());
			trie[now].nxt[c] = nxt;
			trie[nxt].par = now;
			trie[nxt].pc = c;
		}
		now = trie[now].nxt[c];
	}
	trie[now].term++;
}

int getSuffLink(int v);
int getGo(int v, char c);
int getTerm(int v);

int getSuffLink(int v) {
	if (trie[v].suffLink == -1) {
		if (v == 0 || trie[v].par == 0) {
			trie[v].suffLink = 0;
		} else {
			trie[v].suffLink = getGo(getSuffLink(trie[v].par), trie[v].pc);
		}
	}
	// cerr << "v = " << v << " suffLink = " << trie[v].suffLink << endl;
	// if (v == 1) exit(0); 
	return trie[v].suffLink;
}

int getGo(int v, char c) {
	if (trie[v].go.find(c) == trie[v].go.end()) {
		if (trie[v].nxt.find(c) != trie[v].nxt.end()) {
			trie[v].go[c] = trie[v].nxt[c];
		} else {
			if (v == 0) {
				trie[v].go[c] = 0;
			} else {
				trie[v].go[c] = getGo(getSuffLink(v), c);
			}
		}
	}
	// cerr << "v = " << v << " c = " << c << " go = " << trie[v].go[c] << endl; 
	return trie[v].go[c];
}

int getTerm(int v) {
	// cerr << "v = " << v << endl;
	if (!trie[v].findTerm && v != 0) {
		trie[v].term += getTerm(getSuffLink(v));
		trie[v].findTerm = true;
	}
	return trie[v].term;
}

vector<int> solve(const string& t, const vector<string>& a) {
	trie = vector<Node>(1, Node());
	for (const auto& s : a) {
		addString(s);
	}
	// cerr << "buildTrie: ok" << endl;
	vector<int> ans(t.size());
	int now = 0;
	for (int i = 0; i < (int)t.size(); ++i) {
		now = getGo(now, t[i]);
		// cerr << "i = " << i << " getGo = " << now << endl;
		ans[i] = getTerm(now);
		// cerr << "getTerm = " << ans[i] << endl;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	auto L = solve(t, a);
	reverse(all(t));
	for (auto& i : a) {
		reverse(all(i));
	}
	auto R = solve(t, a);
	reverse(all(R));
	ll ans = 0;
	for (int i = 0; i + 1 < (int)t.size(); ++i) {
		ans += (ll)L[i] * R[i + 1];
	}
	cout << ans << endl;
	return 0;
}