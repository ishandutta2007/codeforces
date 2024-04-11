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
int n;
int a[maxn];
int main() {
	cin >> n;
	vector<pi> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i], 
		r.pb(mp(a[i], i));
	sort(r.begin(), r.end());
	for (int j = 0; j < r.size(); j++)
		a[r[j].se] = j + 1;
	vector<pi> res;
	for (int i = 1; i <= n; i++) {
		vector<pi> s;
		for (int j = i + 1; j <= n; j++)
			if (a[j] < a[i]) 
				s.pb(mp(a[j], j));
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		for (auto v : s) {
			int id = v.se;
			res.pb(mp(i, id));
			swap(a[i], a[id]);
		}
	}
	cout << res.size() << endl;
	for (auto h : res)
		printf("%d %d\n", h.fi, h.se);
		
	return 0;
}