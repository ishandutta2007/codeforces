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
int a[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int fl = 0;
		for (int j = 1; j < i; j++)
			if (a[i] % a[j] == 0) fl = 1;
		if (!fl) cnt++;
	}
	cout << cnt << endl;
	return 0;
}