#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int k[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		scanf("%d%d", &n, &p);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &k[i]);
		sort(k + 1, k + n + 1);
		if (p == 1) ans = n % 2;
		else {
			ll dv = 0;
			int fl = 0;
			for (int i = n; i >= 1; i--) {
				if (i != n && k[i + 1] != k[i] && dv) {
					if (k[i + 1] >= k[i] + 25) 
						fl = 1, 
						dv = dv * ksm(p, k[i + 1] - k[i]) % mod;
					else {
						for (int j = 0; j < k[i + 1] - k[i]; j++) {
							dv *= p;
							if (dv > n + 1) fl = 1;
							dv %= mod;
						}
					}
				}
				if (fl || dv > 0) dv--;
				else dv = 1;
			}
			dv = dv * ksm(p, k[1]) % mod;
			if (dv < 0) dv += mod;
			ans = dv;
		}
		printf("%d\n", ans);
	}
	return 0;
}