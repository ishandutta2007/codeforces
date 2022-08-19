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
set<pi> cur;
int a[maxn], b[maxn]; 
int pl[maxn];
int main() {
	int x = 6; 
	for (int i = 1; i <= x; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + x + 1);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), 
		pl[i] = x, 
		cur.insert(mp(b[i] - a[x], i));
	int ans = 2e9;
	while (1) {
		int na = (*--cur.end()).fi - (*cur.begin()).fi;
		chkmin(ans, na);
		pi u = *cur.begin();
		cur.erase(u);
		int id = u.se;
		if (pl[id] != 1) {
			pl[id]--;
			cur.insert(mp(b[id] - a[pl[id]], id));
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}