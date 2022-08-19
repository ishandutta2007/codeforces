#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int mxs = 2005;
char r[3] = {'C', 'H', 'O'};
int nm[maxn];	
int n;
ll ask(vi g) {
	cout << "? ";
	for (int i = 0; i < g.size(); i++)
		cout << r[g[i]];
	cout << endl;
	fflush(stdout);
	int k;
	cin >> k;
	if (k == -1) exit(0);
	ll res = 0;
	for (int j = 0; j < k; j++) {
		int s;
		cin >> s;
		res += (1ll << (s - 1));
		for (int l = 0; l < g.size(); l++)
			nm[s + l] = g[l];
	}
	return res;
}
void otp() {
	int res;
	cout << "! ";
	for (int j = 1; j <= n; j++)
		cout << r[nm[j]];
	cout << endl;
	fflush(stdout);	
	cin >> res; 
}
int gt(vi x, vi y) {
	int ans = 0;
	for (int i = 0; i < x.size() - y.size() + 1; i++) {
		bool fl = 1;
		for (int j = 0; j < y.size(); j++)
			if (y[j] != x[i + j]) fl = 0;
		if (fl) ans += (1 << i);
	}
	return ans;
} 
vector<vi> qs[5];
namespace corner {
	#include <bits/stdc++.h>
	using namespace std;
	
	struct way {
		string w;
		vector<vector<string>> sep;
		double e;
		vector<int> mask;
		bool operator < (const way &r) const {
			return e < r.e;
		}
	} ;
	
	vector<string> a4, a;
	map<vector<string>, pair<double, way>> dp;
	
	const double cost[] = {0, 1.0, 0.25, 1.0 / 9, 1.0 / 16};
	
	int check(string v, string u){
		int n = u.length(), m = v.length(), opt = 0;
		for (int i = 0; i <= n - m; ++i) {
			int cur = 1;
			for (int j = 0; j < m; ++j) if (u[i + j] != v[j]) cur = 0;
			if (cur) opt |= 1 << i;
		}
		return opt;
	}
	
	bool search(vector<string> x, double p){
		if (p < 0) return false;
		if (x.size() == 1) return true;
		if (!dp.count(x)) dp[x].first = 2333;
		if (dp[x].first <= p) return true;
		auto &res = dp[x];
		vector<way> ways;
		for (auto y : a) {
			way k;
			k.w = y;
			map<int, vector<string>> res;
			for (auto z : x) {
				res[check(y, z)].push_back(z);
			}
			int siz = 0;
			for (auto g : res) {
				k.sep.push_back(g.second);
				k.mask.push_back(g.first);
				siz = max(siz, (int)g.second.size());
			}
			//cerr << y << ' ' << res.begin()->first << ' ' << siz << ' ' << x.size() << ' ' << cost[y.length()] << endl;
			double r = (x.size() - siz) * 1.0 / x.size();
			if (r == 0) continue;
			k.e = cost[y.length()] / r;
			ways.push_back(k);
		}
		//exit(0);
		//cerr << x.size() << ' ' << ways[0].e << endl;
		sort(ways.begin(), ways.end());
		for (auto it : ways) {
			double ep = p - cost[it.w.size()];
			bool no = false;
			for (auto u : it.sep) {
				if (!search(u, ep)) {
					no = true;
					break;
				}
			}
			if (!no) {
				pair<double, way> act = make_pair(0, it);
				for (auto u : it.sep) act.first = max(act.first, dp[u].first + cost[it.w.size()]);
				res = min(res, act);
				if (res.first <= p) return true;
			}
		}
		return false;
	}

	void init(){
		for (char c1 = 'a'; c1 <= 'c'; ++c1) {
			string s = ""; s += c1; a.push_back(s);
			for (char c2 = 'a'; c2 <= 'c'; ++c2) {
				string s = ""; s += c1; s += c2; a.push_back(s);
				for (char c3 = 'a'; c3 <= 'c'; ++c3) {
					string s = ""; s += c1; s += c2; s += c3; a.push_back(s);
					for (char c4 = 'a'; c4 <= 'c'; ++c4) {
						string s = ""; s += c1; s += c2; s += c3; s += c4;
						a.push_back(s), a4.push_back(s);
					}
				}
			}
		}
	}
}

void work(vector<vi> s, db cur) {
	if (s.size() == 1) {
		for (int j = 1; j <= 4; j++)
			nm[j] = s[0][j - 1];
		otp();
		return ;
	}
	vector<string> t;
	for (int i = 0; i < s.size(); i++) {
		string g = "";
		for (int j = 0; j < 4; j++)
			g += 'a' + s[i][j];
		t.pb(g);
	}
//	cout << "!!!" << t.size() << ' ' << cur << endl;
	corner::search(t, cur);	
	string w = corner::dp[t].se.w;
	vi u(w.length());
	for (int j = 0; j < u.size(); j++)
		if (w[j] == 'a') u[j] = 0;
		else if (w[j] == 'b') u[j] = 1;
		else u[j] = 2;
//	cout << u.size() << endl;
	int res = ask(u);
	cur -= 1.0 / u.size() / u.size();
	vector<vi> fn;
	for (int j = 0; j < s.size(); j++)
		if (gt(s[j], u) != res) continue;
		else fn.pb(s[j]);
	work(fn, cur);
}
int main() {
	corner::init();
	int t;
	cin >> t;
	for (int i = 0; i < 3; i++) {
		vi r(1);
		r[0] = i;
		qs[1].pb(r);
		for (int j = 0; j < 3; j++) {
			vi u(2);
			u[0] = i, u[1] = j;
			qs[2].pb(u);
			for (int k = 0; k < 3; k++) {
				vi g(3);
				g[0] = i, g[1] = j, g[2] = k;
				qs[3].pb(g);
				for (int l = 0; l < 3; l++) {
					vi e(4);
					e[0] = i, e[1] = j, e[2] = k, e[3] = l;
					qs[4].pb(e);
				}	
			}
		} 
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		vi r(2);
		memset(nm, -1, sizeof(nm));
		if (n == 4) {
			vector<vi> q = qs[4]; 
			work(q, 1.4);
		}
		else {
			r[0] = 0, r[1] = 0, ask(r);
			r[0] = 1, r[1] = 1, ask(r);
			r[0] = r[1] = 2, ask(r);
			r[0] = 0, r[1] = 2, ask(r);
			r[0] = 1, r[1] = 2, ask(r);
			// 1.25
			for (int j = n; j >= 3; j--)
				if (nm[j - 1] == -1 && nm[j] <= 1 && nm[j] != -1)
					nm[j - 1] = 1 - nm[j];
			r.clear();
			bool fl = 0;
			for (int j = 2; j <= n; j++) {
				if (nm[j] != -1) 
					r.pb(nm[j]);
				else {
					fl = 1;
					r.pb(j & 1);
				}
			}
			if (fl)
				ask(r);
			for (int j = 2; j <= n; j++)
				if (nm[j] == -1)
					nm[j] = 1 - (j & 1) ;
			if (nm[1] == -1) {
				nm[1] = 2;
				r.clear();
				for (int i = 1; i <= n; i++)
					r.pb(nm[i]);
				nm[1] = -1;
				ask(r);
				if (nm[1] == -1)
					nm[1] = 1 - nm[2];
			}
			otp();
		}
		
	}
	return 0;
}
/*
CHHOCH
*/