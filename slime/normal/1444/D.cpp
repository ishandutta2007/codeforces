//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
const int W = 1005;
const int mx = 505;
const int pls = mx / 2;
bitset<mx * W> dp[505];
mt19937 h(12312312);
pair<vi, vi> cal(vi x) {
	int n = x.size();
	int cnt = 0;
	l1:shuffle(x.begin(), x.end(), h);
	dp[0][pls * W] = 1;
	for (int i = 1; i <= n; i++) {
		int cur = x[i - 1];
		dp[i] = (dp[i - 1] >> cur) | (dp[i - 1] << cur);
	}
	if (dp[n][pls * W]) {
		int ni = n, nk = pls * W;
		vi u, v;
		while (ni != 0) {
			int cur = x[ni - 1];
			if (nk >= cur && dp[ni - 1][nk - cur])
				ni--, nk -= cur, v.pb(cur);
			else
				ni--, nk += cur, u.pb(cur);  
		}
		return mp(u, v);
	}
	else return mp(vi(0), vi(0)); 
}
vi rd() {
	int sz;
	cin >> sz;
	vi h(sz);
	for (int i = 0; i < sz; i++)
		cin >> h[i];
	return h;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		vi a = rd(), b = rd();
		if (a.size() != b.size()) 
			cout << "No" << endl;
		else {
			pair<vi, vi> x = cal(a), y = cal(b);
			if (x.fi.size() && y.fi.size()) {
				cout << "Yes" << endl;
				int nx = 0, ny = 0;
				vector<pi> cur;
				vi u = x.fi, v = x.se, w = y.fi, t = y.se;
				if (u.size() < v.size()) swap(u, v);
				if (w.size() > t.size()) swap(w, t);
				sort(u.begin(), u.end()),
				reverse(u.begin(), u.end()); 
				sort(v.begin(), v.end()), 
				reverse(v.begin(), v.end()); 
				sort(w.begin(), w.end());
				sort(t.begin(), t.end());
				
				for (int i = 0; i < w.size(); i++)
					cur.pb(mp(u[i], 0)), 
					cur.pb(mp(0, w[i]));
				for (int i = 0; i < v.size(); i++)
					cur.pb(mp(-v[i], 0)), 
					cur.pb(mp(0, -t[i]));
				for (int i = 0; i < u.size() - w.size(); i++)
					cur.pb(mp(u[w.size() + i], 0)), 
					cur.pb(mp(0, -t[v.size() + i]));
					
				for (auto h : cur) {
					nx += h.fi, ny += h.se;
					cout << nx << ' ' << ny << endl;
				}
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}