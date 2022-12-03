#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;

int n;
char c[1000000];

void f(vector<map<int, int> >& a, vector<vector<vector<int> > >& b, int x, string& s) {
	int j = 0;
	b[j][x / n].push_back(x % n);
	for (int i = 0; i < s.length(); i++) {
		int k = s[i] - 'a';
		if (!a[j].count(k)) {
			a[j][k] = a.size();
			a.push_back(map<int, int>());
			b.push_back(vector<vector<int> >(2));
		}
		j = a[j][k];
		b[j][x / n].push_back(x % n);
	}
}

void g(vector<map<int, int> >& a, vector<vector<vector<int> > >& b, int j, vector<vector<bool> >& c, vector<i_i>& p) {
	for (int k = 0; k < 26; k++)
		if (a[j].count(k))
			g(a, b, a[j][k], c, p);
	vector<vector<int> > _b(2);
	for (int x = 0; x < 2; x++)
		for (int i = 0; i < b[j][x].size(); i++)
			if (!c[x][b[j][x][i]])
				_b[x].push_back(b[j][x][i]);
	for (int i = 0; i < _b[0].size() && i < _b[1].size(); i++) {
		int s = _b[0][i], t = _b[1][i];
		c[0][s] = c[1][t] = true;
		p.push_back(i_i(s, t));
	}
}

int main() {
	cin >> n;
	vector<map<int, int> > a(1);
	vector<vector<vector<int> > > b;
	b.push_back(vector<vector<int> >(2));
	for (int x = 0; x < n * 2; x++) {
		scanf("%s", c);
		string s = c;
		f(a, b, x, s);
	}
	ll sum = 0;
	for (int j = 1; j < a.size(); j++)
		sum += min(b[j][0].size(), b[j][1].size());
	vector<vector<bool> > c(2, vector<bool>(n));
	vector<i_i> p;
	g(a, b, 0, c, p);
	cout << sum << endl;
	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].first + 1, p[i].second + 1);
}