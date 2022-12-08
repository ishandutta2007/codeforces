#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll L;
	cin >> n >> L;	
	ll ct[31];
	ct[0] = 1LL;
	for (int i = 1; i < n; i++) {
		ct[i] = ct[i-1]*2LL;
	}
	ll co[31];
	for (int i = 0; i < n; i++) {
		cin >> co[i];
	}
	for (int i = 1; i < n; i++) {
		co[i] = min(co[i], co[i-1]*2LL);
	}
	ll ans = L*co[0];
	int cur = L;
	ll ccost = 0LL;
	for (int i = n-1; i >= 0; i--) {
		ll take = (cur+0LL)/ct[i];
		if (ct[i]*take < cur) take+=1LL;
		ans = min(ans, ccost + take*co[i]);
		
		take = (cur+0LL)/ct[i];
		cur -= take*ct[i];
		ccost += take*co[i];
	}
	cout << ans << endl;
	cin >> ans;

}