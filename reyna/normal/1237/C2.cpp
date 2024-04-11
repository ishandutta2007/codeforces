
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int mark[N], o[N], x[N], y[N], z[N];
set<pair<int, int>> st;
map<int, set<pair<int, int>>> f;
map<pair<int, int>, set<pair<int, int>>> s;
void add(int j) {	
	st.insert(mp(x[j], j));
	f[x[j]].insert(mp(y[j], j));
	s[mp(x[j], y[j])].insert(mp(z[j], j));
}
void rem(int j) {
	st.erase(mp(x[j], j));
	f[x[j]].erase(mp(y[j], j));
	s[mp(x[j], y[j])].erase(mp(z[j], j));
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> x[j] >> y[j] >> z[j];
		add(j);
	}
	for (int j = 0; j < n; ++j) if (!mark[j]) {
		rem(j);
		mark[j] = 1;
		int cx = -1;
		{
			auto it = st.lower_bound(mp(x[j], -1));
			if (it == st.end()) {
				--it;	
			}
			cx = it->first;
		}
		int cy = -1;
		{
			auto it = f[cx].lower_bound(mp(y[j], -1));
			if (it == f[cx].end()) {
				--it;
			}
			cy = it->first;
		}
		int id = -1;
		{
			auto it = s[mp(cx, cy)].lower_bound(mp(z[j], -1));
			if (it == s[mp(cx, cy)].end()) {
				--it;
			}
			id = it->second;
		}
		mark[id] = 1;
		rem(id);
		cout << j + 1 << ' ' << id + 1 << '\n';
	}
}