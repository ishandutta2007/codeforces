#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct pt {
	int x, y;
	pt(){;
	}
	void rd() {
		cin >> x >> y;
	}
	bool operator == (const pt &r)const {
		return x == r.x && y == r.y;
	}
}u[3][2];
ll sqr(int a) {
	return 1ll * a * a;
}
ll dis(pt a, pt b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}
bool check(ll a, ll b, ll c) {
	if (c < a + b) return 0;
	c -= (a + b);
	return c * c == 4 * a * b;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int i = 0; i < 3; i++)
			u[i][0].rd(), u[i][1].rd();
		vector<pi> cur; 
		for (int i = 0; i < 3; i++)
			for (int j = i + 1; j < 3; j++) {
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						if (u[i][k] == u[j][l]) cur.pb(mp(i, j));
			}
		if (cur.size() != 1) cout << "NO" << endl;
		else {
			int i = cur[0].fi, j = cur[0].se;
			int e = 3 - i - j;
		//	cout << i << ' ' << j << ' ' << e << endl;
			int f, g;
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					if (u[i][k] == u[j][l]) f = k, g = l;
			ll d1 = dis(u[i][f], u[i][f ^ 1]), d2 = dis(u[j][g], u[j][g ^ 1]), d3 = dis(u[i][f ^ 1], u[j][g ^ 1]);
			if (d1 + d2 < d3) cout << "NO" << endl;
			else {
				if (check(d1, d2, d3) || check(d1, d3, d2) || check(d2, d3, d1)) cout << "NO" << endl;
				else {
					int pl = 0;
					int fl = 0;
					for (int m = 0; m < 2; m++) {
						int cf = 0;
						ll d1 = dis(u[i][0], u[e][m]), d2 = dis(u[i][1], u[e][m]), d3 = dis(u[i][0], u[i][1]);	
					//	cout << m << ' ' << cf << ' ' << d1 << ' ' << d2 << ' ' << d3 << endl;
						if (check(d1, d2, d3) && max(d1, d2) <= 16 * min(d1, d2)) cf = 1;
						else {
							d1 = dis(u[j][0], u[e][m]), d2 = dis(u[j][1], u[e][m]), d3 = dis(u[j][0], u[j][1]);
							if (check(d1, d2, d3) && max(d1, d2) <= 16 * min(d1, d2)) cf = 2;
						}
					
						fl ^= cf;
					}
					if (fl != 3) cout << "NO" << endl;
					else cout << "YES" << endl;
				}
			}
		} 
	} 
	return 0;
}