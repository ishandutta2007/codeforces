#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e5L + 11;

int g[N], p[N], t[N];

map <int, vi> mp[3];

int x[N], y[N];

bool cmp(int i, int j) {
	return p[i] < p[j];
}

using pii = pair <int, int>;

bool cmp2(pii a, pii b) {
	if(a.sec == b.sec)
		return a.fir < b.fir;
	return a.sec > b.sec;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, w, h; cin >> n >> w >> h;
	for(int i = 1; i <= n; i ++) {
		cin >> g[i] >> p[i] >> t[i];
		mp[g[i]][p[i] - t[i]].pb(i);
		if(g[i] == 1) {
			x[i] = p[i]; y[i] = h;
		} else {
			y[i] = p[i]; x[i] = w;
		}
	}
	
	for(int i = -100000; i <= 100000; i ++) if(mp[1].count(i) && mp[2].count(i)) {
		//cout << "!" << i << '\n';
		sort(mp[1][i].begin(), mp[1][i].end(), cmp);
		sort(mp[2][i].begin(), mp[2][i].end(), cmp);
		reverse(mp[2][i].begin(), mp[2][i].end());
		vector <pii> v;
		for(int j : mp[1][i])
			v.pb({x[j], y[j]});
		for(int j : mp[2][i])
			v.pb({x[j], y[j]});
		sort(v.begin(), v.end(), cmp2);
		int t = 0;
		for(int j : mp[2][i]) {
			//cout << j << '\n';
			x[j] = v[t].fir; y[j] = v[t].sec;
			t ++;
		}
		for(int j : mp[1][i]) {
			//cout << j << '\n';
			x[j] = v[t].fir; y[j] = v[t].sec;
			t ++;
		}
	}
	for(int i = 1; i <= n; i ++)
		cout << x[i] << ' ' << y[i] << '\n';
	return 0;
}