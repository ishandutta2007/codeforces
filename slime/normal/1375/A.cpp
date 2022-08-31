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
/*11469018098471
7877074948913
68804730901483
*/
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int fl[105];
int b[105];
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(fl, 0, sizeof(fl));
		int n;
		cin >> n;
		vector<pi> x;
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			x.pb(mp(abs(a), i));
		}
		sort(x.begin(), x.end());
		fl[0] = fl[n + 1] = 1;
		reverse(x.begin(), x.end());
		int ss = 1;
		for (auto t : x) {
			int id = t.se;
			fl[id] = 1;
			if (fl[id - 1] == fl[id + 1]) 
				b[id] = abs(t.fi);
			else {
				int res = ss;
				if (fl[id - 1]) res *= -1;
				b[id] = abs(t.fi) * res;
				ss *= -1;
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", b[i]);
		}
		cout << endl;
	} 
	return 0;
}