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
int m, n;
int l[maxn]; 
int p[maxn];
ll s[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		int mx = p[1];
		int nd = 0;
		for (int i = 2; i <= n; i++)
			nd = max(nd, mx - p[i]), 
			mx = max(mx, p[i]);
		for (int j = 0; j < 32; j++) {
			if ((1ll << j) - 1 >= nd) {
				printf("%d\n", j);
				break;
			}
		}
	} 
	return 0;
}