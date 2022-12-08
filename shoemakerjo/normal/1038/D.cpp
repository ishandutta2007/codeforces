#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 500010
const ll inf = 1234567890LL;

int n;
ll a[maxn];
ll pref[maxn], suf[maxn];
ll minbef[maxn];
ll minaft[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pref[0] = abs(a[0]);
	suf[n-1] = abs(a[n-1]);
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i-1] + abs(a[i]);
	}
	for (int i = n-2; i >= 0; i--) {
		suf[i] = suf[i+1] + abs(a[i]);
	}
	fill(minaft, minaft+maxn, inf);
	fill(minbef, minbef+maxn, inf);
	for (int i = 1; i < n; i++) {
		minbef[i] = min(minbef[i-1], a[i-1]);
	}
	for (int i = n-2; i >= 0; i--) {
		minaft[i] = min(minaft[i+1], a[i+1]);
	}
	ll ans = 0LL-inf*1LL*n;
	for (int i = 0; i < n; i++) {
		//consider this as max
		ll cans = a[i];
		if (i > 0) cans += pref[i-1];
		if (i < n-1) cans += suf[i+1];
		if (i > 0) {
			if (minbef[i] > 0) cans -= 2*minbef[i];
		}
		if (i < n-1) {
			if (minaft[i] > 0) cans -= 2*minaft[i];
		}
		ans = max(ans, cans);
	}
	cout << ans << endl;
	

}