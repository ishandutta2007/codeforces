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
int p[maxn], f[maxn], e[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] > p[i - 1]) f[i] = f[i - 1] + 1;
		else f[i] = 1;
		chkmax(mx, f[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (p[i] > p[i + 1]) e[i] = e[i + 1] + 1;
		else e[i] = 1;
		chkmax(mx, e[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] == mx) cnt++;
		if (e[i] == mx) cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == mx && e[i] == mx && cnt == 2 && mx % 2 == 1) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}