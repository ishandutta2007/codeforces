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
int a[maxn], b[maxn]; 
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int c[2] = {0, 0};
		for (int i = 1; i <= 2 * n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == 0) a[++c[0]] = abs(y);
			else b[++c[1]] = abs(x);
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		db ans = 0;
		for (int i = 1; i <= n; i++) 
			ans += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]); 
		printf("%.10lf\n", ans);
	}
	return 0;
}