//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 205 /*rem*/
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
int a[maxn];
vi ur;
vector<pi> re;
pi bg;
void ask(int d) {
	cout << "+ " <<  d << endl;
	fflush(stdout);
	ur.pb(d);
	int x, y;
	cin >> x >> y;
	re.pb(mp(x, y));
} 
int d[maxn];
vector<vi> res; 
pi chk(vi g) {
	int a = 0, b = 0;
	for (int i = 0; i < g.size() - 2; i++)
		b += g[i] * g[i + 1] * g[i + 2];
	for (auto v : g)
		a += d[v];
	return mp(a, b);
}
void jug(vi cur) {
	for (int i = re.size() - 1; i >= 0; i--) {	
			pi ug = chk(cur);	
			if (ug != re[i]) return;
			if (i == 0) res.pb(cur);
			else {
				cur[ur[i] - 1]--;
				if (cur[ur[i] - 1] < 0) return;
			}
		}
}
int lt(int k) {
	return re.size()  -k;
}
int gt(int dv, int f0) {
	for (int l = 0; l < maxn; l++) {
		if (l == 0 && !f0) continue;
		if (d[l + 1] - d[l] == dv) return l + 1;
	}
}
int main() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	re.pb(mp(x, y));
	ur.pb(0);
	for (int i = 0; i < maxn; i++)	
		d[i] = i * (i - 1) * (i - 2) / 6;
	memset(a, -1, sizeof(a));
	ask(3), ask(1); int fg = (re[lt(1)].se - re[lt(2)].se);
	if (fg == 0) fg = 1;
	else fg = 0;
	ask(2); a[2] = gt(re[lt(1)].fi - re[lt(2)].fi, fg);
	ask(1); a[1] = gt(re[lt(1)].fi - re[lt(2)].fi, 0);
 	a[3] = (re[lt(1)].se - re[lt(2)].se) / a[2];
 	for (int i = 4; i <= n - 1; i++) {
 		int q0 = 0;
		if (i != 4) {
			int dm = re[re.size() - 1].se - re[re.size() - 2].se;
			if (dm == a[i - 2] * a[i - 3]) q0 = 1;
			else q0 = 0;
		}	
		else {
			int dm = re[re.size() - 2].se - re[re.size() - 3].se;
			if (dm == (a[1] - 1) * a[3]) q0 = 1;
			else q0 = 0;
		}
		ask(i);
		a[i] = gt(re[lt(1)].fi - re[lt(2)].fi, q0);
	}
//	for (int i = 1; i <= n - 1; i++)
//		cout << a[i] << ' ';
	vi cur(n);
	for (int i = 1; i <= n; i++)
		cur[i - 1] = a[i];
	for (int m = 0; m <= n; m++)
		cur[n - 1] = m, jug(cur);
	if (res.size() >= 2) while(1);
//	cout << res.size() << endl;
	cout << "! ";
	for (auto v : res[0])
		cout << v << ' ';
	cout << endl;
	fflush(stdout);
	return 0;
}
/*
5
1 6
2 9
2 18
5 24
5 40
6 44

*/