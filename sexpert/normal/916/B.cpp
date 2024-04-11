#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _cnt[300000];
int* cnt = _cnt + 150000;

int main() {
	ll n, k;
	cin >> n >> k;
	int mx = -1;
	int tot = __builtin_popcountll(n);
	if(tot > k) {
		cout << "No\n";
		return 0;
	}
	for(ll i = 0; i <= 63; i++)
		if(n & (1ll << i)) {
			cnt[i] = 1;
			mx = i;
		}
	cout << "Yes\n";

	for(int i = 70; i >= -70; i--) {
		if(tot + cnt[i] <= k) {
			tot += cnt[i];
			cnt[i - 1] += 2*cnt[i];
			cnt[i] = 0;
		}
		else break;
	}
	int p = 0;
	for(p = -70;;p++)
		if(cnt[p])
			break;
	while(tot < k) {
		cnt[p]--;
		p--;
		cnt[p] = 2;
		tot++;
	}
	for(int i = 70; i >= -120000; i--)
		for(int j = 0; j < cnt[i]; j++)
			cout << i << " ";
	cout<< endl;
}