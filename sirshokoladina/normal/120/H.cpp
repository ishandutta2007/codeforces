#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

string s[300];
vector<string> t;
int mp[1000000];
vector<string> w;
int u[20000];
vector<int> e[300];
int p1[300], p2[1000000];
int udfs[300];
vector<int> v;

bool dfs(int a) {
	if (udfs[a]) {
		return 0;
	}
	udfs[a] = 1;
	v.push_back(a);
	v.push_back(a);
	forn (i, e[a].size()) {
		v[v.size() - 1] = e[a][i];
		if (p2[e[a][i]] == -1) {
			return 1;
		} else {
			if (dfs(p2[e[a][i]])) {
				return 1;
			}
		}
	}
	v.pop_back();
	v.pop_back();
	return 0;
}

int hash(string s) {
	int ans = 0;
	forn (i, 4) {
		ans *= 27;
		if (i < (int)s.size()) {
			ans += s[i] - 'a' + 1;
		}
	}
	return ans;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, n) {
		cin >> s[i];
	}
	forn (i, 26) {
		string w1(1, 'a' + i);
		t.push_back(w1);
		forn (j, 26) {
			string w2 = w1 + string(1, 'a' + j);
			t.push_back(w2);
			forn (k, 26) {
				string w3 = w2 + string(1, 'a' + k);
				t.push_back(w3);
				forn (l, 26) {
					string w4 = w3 + string(1, 'a' + l);
					t.push_back(w4);
				}
			}
		}
	}
	forn (i, t.size()) {
		mp[hash(t[i])] = i;
	}
	forn (i, n) {
		forn (j, 20000) {
			u[j] = 0;
		}
		w = vector<string>(1, "");
		forn (j, s[i].size()) {
			if ((int)e[i].size() > n) {
				break;
			}
			int w0 = w.size();
			forn (k, w0) {
				if ((int)e[i].size() > n) {
					break;
				}
				string q = w[k] + string(1, s[i][j]);
				int h = hash(q);
				int num = mp[h];
				int r = 0;
				forn (l, e[i].size()) {
					if (e[i][l] == num) {
						r = 1;
					}
				}
				if (!r) {
					e[i].push_back(num);
				}
				if (q.size() < 4) {
					h /= 27;
					if (!u[h]) {
						w.push_back(q);
						u[h] = 1;
					}
				}
			}
		}
	}
	forn (i, 1000000) {
		p2[i] = -1;
	}
	forn (i, n) {
		forn (j, n) {
			udfs[j] = 0;
		}
		v.clear();
		if (!dfs(i)) {
			cout << -1;
			return 0;
		}
		forn (i, v.size() / 2) {
			p1[v[2 * i]] = v[2 * i + 1];
			p2[v[2 * i + 1]] = v[2 * i];
		}
	}
	forn (i, n) {
		cout << t[p1[i]] << endl;
	}
}