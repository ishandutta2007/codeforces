#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 200010;

int n;

ll mymax[maxn];
ll mycount[maxn];

//just merge everything into the largest guy
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int mi;

	ll tmax = 0;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> mi;
		mycount[i] = mi;
		for (int j = 0; j < mi; j++) {
			cin >> cur;
			mymax[i] = max(mymax[i], cur);
		}
		tmax = max(tmax, mymax[i]);
	}

	ll ans = 0LL;

	for (int i = 0; i < n; i++) {
		ans += mycount[i] * (tmax - mymax[i]);
	}

	cout << ans << endl;

}