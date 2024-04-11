#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
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
int r, c;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int main() {
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (c == 1) {
		for (int i = 1; i <= r; i++)
			printf("%d\n", i + 1);
		return 0;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int x = i, y = r + j;
			printf("%d ", x * y / gcd(x, y));
		}
		printf("\n");
	}
	return 0;
}