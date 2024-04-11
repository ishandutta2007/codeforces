#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
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
int a[maxn][maxn];
int main() {
	int n;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i += 4) {
		for (int j = 0; j < n; j += 4) {
			for (int k = 0; k < 4; k++)
				for (int l = 0; l < 4; l++)
					a[i + k][j + l] = s + 4 * k + l;
			s += 16;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}