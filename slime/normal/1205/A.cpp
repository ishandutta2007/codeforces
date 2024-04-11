#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
int a[maxn];
int main() {
	int n;
	cin >> n;
	if (!(n & 1)) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int ns = 1;
		for (int i = 1; i <= n; i++) {
			if (i & 1) a[i] = ns, a[n + i] = ns + 1;
			else a[i] = ns + 1, a[n + i] = ns;
			ns += 2;
		}
		for (int i = 1; i <= 2 * n; i++)
			printf("%d ", a[i]);
	} 
	return 0;
}