#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

vector<int> e[1000010];
int p[1000010];
int w[1000010];

int hash(string s) {
	int ans = 0;
	forn (i, s.size()) {
		(ans *= 97) += s[i];
	}
	return ans;
}

vector<int> g;

int calc(int v, int i) {
	if (w[v] == g[i]) {
		i++;
	}
	int ans = 0;
	if (i == g.size()) {
		ans += 1;
		i--;
	}
	forn (j, e[v].size()) {
		ans += calc(e[v][j], i);
	}
	return ans;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	string s;
	getline(cin, s);
	vector<int> q;
	q.pb(0);
	q[0] = 0;
	w[0] = -2348953;
	int n = 1;
	for (int i = 0; i < s.size(); ) {
		i++;
		bool q1 = (s[i] == '/');
		if (q1) {
			i++;
		}
		int j = i;
		while (j < s.size() && s[j] != '>' && s[j] != '/') {
			j++;
		}
		int name = hash(s.substr(i, j - i));
		bool q2 = (s[j] == '/');
		if (q2) {
			j++;
		}
		j++;
		if (!q1) {
			p[n] = q[q.size() - 1];
			e[p[n]].pb(n);
			w[n] = name;
			q.pb(n);
			n++;
		}
		if (q1 || q2) {
			q.pop_back();
		}
		i = j;
	}
	int T;
	cin >> T;
	getline(cin, s);
	forn (qwe, T) {
		getline(cin, s);
		g.clear();
		for (int i = 0; i < s.size(); ) {
			int j = i;
			while (j < s.size() && s[j] != ' ') {
				j++;
			}
			g.pb(hash(s.substr(i, j - i)));
			if (s[j] == ' ') {
				j++;
			}
			i = j;
		}
		cout << calc(0, 0) << endl;
	}
	return 0;
}