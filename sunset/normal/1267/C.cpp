#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define db double
#define mod 998244353
#define maxn 10005
using namespace std;
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}
int d[maxn];
int fl = 1;
vector<pi> eg;
void fail() {
	cout << -1 << endl;
	exit(0);
}
void work(vector<pi> x) {
	if (!x.size()) return ;
	if (x.size() == 1) fail();
	if (x[0].fi >= 3) fail();
 	vector<pi> y;
	if (x[0].fi == 1) {
		if (x[x.size() - 1].fi == 1) {
			if (x.size() > 2) fail(); 
			else {
				eg.pb(mp(x[0].se, x[1].se));
				return ;
			}
		}
		else {
			int pl = x.size() - 1;
			if (x[pl].fi % 2 == 0) 
				for (int j = pl - 1; j >= 1; j--) {
					if (x[j].fi % 2 == 1 && x[j].fi > 1) {
						pl = j;
						break;
					}
				}
			x[pl].fi--;
			eg.pb(mp(x[0].se, x[pl].se));
			for (int i = 1; i < x.size(); i++)
				y.pb(x[i]);
		}
	}
	else {
		if (x[x.size() - 1].fi == 2) {
			if (x.size() == 2) fail();
			else {
				for (int i = 0; i < x.size(); i++)
					eg.pb(mp(x[i].se, x[(i + 1) % x.size()].se));
				return ;
			}
		}
		else {
			if (x[1].fi > 2) fail();
			else {
				eg.pb(mp(x[0].se, x[x.size() - 1].se));
				eg.pb(mp(x[1].se, x[x.size() - 1].se));
				eg.pb(mp(x[0].se, x[1].se));
				x[x.size() - 1].fi -= 2;
				for (int i = 2; i < x.size(); i++)
					y.pb(x[i]);
			}
		}
	}
	sort(y.begin(), y.end());
	work(y);
}
int main() {
	int n;
	cin >> n;
	vector<pi> x;
	for (int i = 1; i <= n; i++) {
		int d;
		scanf("%d", &d);
		x.pb(mp(d, i));
	}
	sort(x.begin(), x.end());
	work(x);
	cout << eg.size() << endl;
	for (int i = 0; i < eg.size(); i++)
		cout << 2 << ' ' << eg[i].fi << ' ' << eg[i].se << endl;
  	return 0;
}
/*
15
1 4 3 2 2 2 2 2 4 4 2 2 2 2 2
*/