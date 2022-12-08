#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define maxk 31
#define ll long long

int n, k;
int nums[maxn];
int pxor[maxn];
int big;
map<int, int> freq;
set<int> stuff;

ll c2(ll cur) {
	return cur * (cur-1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i <= n; i++)  {
		pxor[i] = pxor[i-1] ^ nums[i];
	}
	big = (1 << k) - 1;
	ll ans = n  * 1LL * (n-1LL) / 2LL;
	ans += n;
	int cur;
	for (int i = 1; i <= n; i++) {
		cur = min(pxor[i], big - pxor[i]);
		freq[cur]++;
		stuff.insert(cur);
	}
	for (int vv : stuff) {
		int cf = freq[vv];
		if (cf == 1) continue;
		if (vv == 0) {
			ll minsub = ans;
			for (int j = 0; j <= cf; j++) {
				minsub = min(minsub, j + c2(j) + c2(cf-j));
			}
			ans -= minsub;
		}
		else {
			ll minsub = ans;
			for (int j = 0; j <= cf; j++) {
				minsub = min(minsub, c2(j) + c2(cf-j));
			}
			ans -= minsub;
		}
	}
	cout << ans << endl;



	
}