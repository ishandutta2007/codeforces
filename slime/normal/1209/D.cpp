#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int fa[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		fa[gfa(x)] = gfa(y);
	}
	int ans = n;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) ans--;
	cout << k - ans << endl;
	return 0;
}