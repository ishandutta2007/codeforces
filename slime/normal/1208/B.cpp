#include <bits/stdc++.h>
using namespace std;
#define maxn 2010
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
int n;
int a[maxn];
map<int, int>id;
int cnt[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!id[a[i]]) id[a[i]] = i;
		a[i] = id[a[i]];
	}
	int ans = maxn;
	for (int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt));
		int s = 0;
		for (int j = 1; j <= n; j++)
			cnt[a[j]]++;
		for (int j = 1; j <= n; j++)
			if (cnt[j] >= 2) s++;
		for (int j = i; j <= n + 1; j++) {
			if (s <= 0) ans = min(ans, j - i);
			cnt[a[j]]--;
			if (cnt[a[j]] == 1) s--;
		}
	}
	cout << ans << endl;
	return 0;
}