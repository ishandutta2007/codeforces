#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int N, M;
int unko[100];
bool mention[100][100];

bool f(int j, int prev, vector<vector<int> >& memo, vector<int>& ans) {
	if (memo[j][prev] != -1) return memo[j][prev];
	if (j == M) return memo[j][prev] = true;
	rep(i, N) if (i != prev && (unko[j] == -1 || i == unko[j]) && !mention[j][i])
		if (f(j + 1, i, memo, ans)) {
			ans[j] = i;
			return memo[j][prev] = true;
		}
	return memo[j][prev] = false;
}

void solve() {
	cin >> N;
	vector<string> name(N);
	map<string, int> mp;
	rep(i, N) cin >> name[i], mp[name[i]] = i;
	cin >> M; cin.ignore();
	vector<string> sender(M), text(M);
	rep(j, M) {
		string s; getline(cin, s);
		int k;
		for (k = 0; s[k] != ':'; k++);
		sender[j] = s.substr(0, k);
		text[j] = s.substr(k + 1);
	}
	rep(j, M) {
		if (sender[j] == "?") unko[j] = -1;
		else unko[j] = mp[sender[j]];
		rep(i, N) mention[j][i] = false;
		string s = text[j];
		int L = s.length();
		vector<int> v;
		v.pb(-1);
		rep(k, L)
			if (s[k] == '.' || s[k] == ',' || s[k] == '!' || s[k] == '?' || s[k] == ' ')
				v.pb(k);
		v.pb(L);
		for (int k = 0; k + 1 < v.size(); k++) {
			int l = v[k] + 1, r = v[k + 1];
			string t = s.substr(l, r - l);
			if (mp.count(t)) mention[j][mp[t]] = true;
		}
	}
	vector<vector<int> > memo(M + 1, vector<int>(N + 1, -1));
	vector<int> ans(M);
	if (!f(0, N, memo, ans)) {
		cout << "Impossible" << endl;
		return;
	}
	rep(j, M) cout << name[ans[j]] << ':' << text[j] << endl;
}

int main() {
	int T; cin >> T;
	while (T--) solve();
}