#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
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
char inp[65][65];
int check(int a, int b) {
	if (inp[a][b] == 'A') return 1;
	return 0;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll x;
		cin >> x;
		if ((x % 14 <= 6) && (x % 14 != 0) && (x > 14)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}