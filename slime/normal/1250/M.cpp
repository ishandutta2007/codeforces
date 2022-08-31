#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int p[maxn], dep[maxn], s[maxn];
int main() {
	int n;
	cin >> n;
	s[0]++;
	for (int i = 2; i <= n; i++)
		scanf("%d", &p[i]), 
		dep[i] = dep[p[i]] + 1, s[dep[i]]++;
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans += s[i] % 2;
	cout << ans << endl;
	return 0;
}