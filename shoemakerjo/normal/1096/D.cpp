#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 100010;

const ll inf = 1e18;

int n;
ll nums[maxn];
string s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	ll d0 = 0;
	ll dh = inf;
	ll dha = inf;
	ll dhar = inf;

	for (int i = 1; i <= n; i++) {

		if (s[i] == 'd') {
			dhar = dhar + nums[i];
		}
		else if (s[i] == 'r') {
			dhar = min(dhar, dha);
		}
		//else there is no change

		if (s[i] == 'r') {
			dha = dha + nums[i];
		}
		else if (s[i] == 'a') dha = min(dha, dh);

		if (s[i] == 'a') {
			dh = dh + nums[i];
		}
		else if (s[i] == 'h') {
			dh = min(dh, d0);
		}

		if (s[i] == 'h') {
			d0 = d0 + nums[i];
		}

		d0 = min(d0, inf);
		dh = min(dh, inf);
		dha = min(dha, inf);
		dhar = min(dhar, inf);

	}

	ll ans = inf;
	ans = min(ans, d0);
	ans = min(ans, dh);
	ans = min(ans, dha);
	ans = min(ans, dhar);

	cout << ans << endl;
}