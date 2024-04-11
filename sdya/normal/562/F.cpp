#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;

struct Node {
	Node *a[26];
	Node() {
		for (int i = 0; i < 26; ++i) {
			a[i] = nullptr;
		}
	}
};

void add(Node *root, const string &s) {
	Node *current = root;
	for (int i = 0; i < s.size(); ++i) {
		if (current->a[s[i] - 'a'] == nullptr) {
			current->a[s[i] - 'a'] = new Node();
		}
		current = current->a[s[i] - 'a'];
	}
}

string getMatch(Node *root, const string &s) {
	string res = "";
	Node *current = root;
	for (int i = 0; i < s.size(); ++i) {
		if (current->a[s[i] - 'a'] != nullptr) {
			res += s[i];
			current = current->a[s[i] - 'a'];
		} else {
			break;
		}
	}
	return res;
}

int getLcp(const string &s1, const string &s2) {
	int len = min(s1.size(), s2.size());
	int res = 0;
	for (int i = 0; i < len; ++i) {
		if (s1[i] == s2[i]) {
			++res;
		} else {
			break;
		}
	}
	return res;
}

pair < string, int > a[maxN];
pair < string, int > b[maxN];
pair < string, int > c[2 * maxN];

vector < pair < int, int > > res;
int ans = 0;

bool comp(const pair < string, int > &s1, const pair < string, int > &s2) {
	return s1.first.size() < s2.first.size();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
		c[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
		c[i + n] = b[i];
		c[i + n].second = -c[i + n].second;
	}
	//sort(b + 1, b + n + 1);
	//sort(a + 1, a + n + 1);
	sort(c + 1, c + 2 * n + 1);

	set < pair < int, int > > S;
	set < int > T;
	for (int i = 1; i < 2 * n; ++i) {
		int x = (c[i].second > 0 ? 1 : -1);
		int y = (c[i + 1].second > 0 ? 1 : -1);
		if (x * y < 0) {
			S.insert(make_pair(getLcp(c[i].first, c[i + 1].first), i));
		}
	}
	for (int i = 1; i <= 2 * n; ++i) {
		T.insert(i);
	}

	while (!T.empty()) {
		pair < int, int > p = *S.rbegin();
		S.erase(p);
		ans += p.first;

		set < int > ::iterator it = T.find(p.second);
		set < int > ::iterator jt = it;
		++jt;

		int lIndex = -1;
		if (it != T.begin()) {
			set < int > ::iterator r = it;
			--r;
			lIndex = *r;
		}
		int rIndex = -1;
		{
			set < int > ::iterator r = jt;
			++r;
			if (r != T.end()) {
				rIndex = *r;
			}
		}

		int u = *it;
		int v = *jt;
		res.push_back(make_pair(max(c[u].second, c[v].second), -min(c[u].second, c[v].second)));
		T.erase(u);
		T.erase(v);

		if (lIndex != -1) {
			int x = (c[lIndex].second > 0 ? 1 : -1);
			int y = (c[u].second > 0 ? 1 : -1);
			if (x * y < 0) {
				S.erase(make_pair(getLcp(c[lIndex].first, c[u].first), lIndex));
			}
		}
		if (rIndex != -1) {
			int x = (c[v].second > 0 ? 1 : -1);
			int y = (c[rIndex].second > 0 ? 1 : -1);
			if (x * y < 0) {
				S.erase(make_pair(getLcp(c[v].first, c[rIndex].first), v));
			}
		}

		if (lIndex != -1 && rIndex != -1) {
			int x = (c[lIndex].second > 0 ? 1 : -1);
			int y = (c[rIndex].second > 0 ? 1 : -1);
			if (x * y < 0) {
				S.insert(make_pair(getLcp(c[lIndex].first, c[rIndex].first), lIndex));
			}
		}
	}

	/*Node *root = new Node();
	for (int i = 1; i <= n; ++i) {
		add(root, b[i].first);
	}

	vector < pair < string, int > > g(n);
	for (int i = 1; i <= n; ++i) {
		g[i - 1] = make_pair(getMatch(root, a[i].first), a[i].second);
	}

	Node *aroot = new Node();
	for (int i = 0; i < n; ++i) {
		add(aroot, g[i].first);
	}

	set < pair < string, int > > S;
	for (int i = 1; i <= n; ++i) {
		S.insert(make_pair(getMatch(aroot, b[i].first), b[i].second));
	}

	sort(g.begin(), g.end(), comp);
	reverse(g.begin(), g.end());
	for (int i = 0; i < g.size(); ++i) {
		set < pair < string, int > > ::iterator it = S.lower_bound(make_pair(g[i].first, -1));
		if (it != S.end() && it->first == g[i].first) {
			ans += g[i].first.size();
			res.push_back(make_pair(g[i].second, it->second));
			S.erase(it);
		}
	}*/

	/*int bound = 0;
	for (int i = 1; i <= n; ++i) {
		string t = getMatch(root, a[i].first);
		int index = lower_bound(b + 1, b + n + 1, make_pair(t, -1)) - b;
		if (index <= bound) {
			index = bound + 1;
		}
		int lcp = 0;
		if (index != n + 1) {
			lcp = getLcp(a[i].first, b[index].first);
		}
		if (index == n + 1 || lcp == 0) {
			continue;
		} else {
			ans += lcp;
			res.push_back(make_pair(a[i].second, b[index].second));
			bound = index;
		}
	}

	vector < int > ua(n + 1, false), ub(n + 1, false);
	for (int i = 0; i < res.size(); ++i) {
		ua[res[i].first] = true;
		ub[res[i].second] = true;
	}
	vector < int > x, y;
	for (int i = 1; i <= n; ++i) {
		if (!ua[i]) {
			x.push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!ub[i]) {
			y.push_back(i);
		}
	}
	for (int i = 0; i < x.size(); ++i) {
		res.push_back(make_pair(x[i], y[i]));
	}*/

	cout << ans << endl;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << " " << res[i].second << endl;
	}


	return 0;
}