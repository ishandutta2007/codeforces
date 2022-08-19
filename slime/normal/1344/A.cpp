#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
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
int a[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)	 a[j] =0 ;
		int fl = 1;
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			x += j;
			 x %= n;
			if (x < 0) x += n;
			if (a[x]) fl = 0;
			a[x] = 1;
		}
		if (!fl) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}