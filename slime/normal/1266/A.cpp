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
char inp[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", inp);
		int l = strlen(inp);
		bool fl = 0;
		for (int j = 0; j < l; j++)
			for (int k = 0; k < l; k++) {
				if ( j == k) continue;
				int ns = (inp[j] - '0') * 10 + inp[k] - '0';
				if (ns % 20 == 0) fl = 1;
			}
		if (fl) {
			int res = 0;
			for (int j = 0; j < l; j++)
				res += inp[j] - '0';
			if (res % 3 != 0) fl = 0;
		}
		if (fl) cout << "red" << endl;
		else cout << "cyan" << endl;
	}
	return 0;
}