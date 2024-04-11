#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int inf = 1e9 + 7;

void solve(){
	int n, x;

	cin >> n >> x;

	int cnt = inf, mx = 0, mx_diff = 0;;
	for(int i = 0; i < n; ++i){
		int d, h;

		cin >> d >> h;

		mx = max(mx, d);
		mx_diff = max(d - h, mx_diff);

		if(d >= x){
			cnt = 1;
			continue;
		}
	}

	if(x <= mx){
		cout << "1\n";
		return;
	}
	x -= mx;
	cnt = 1;

	if(mx_diff == 0){
		cout << "-1\n";
		return;
	}

	cnt += x / mx_diff;
	cnt += (bool)(x % mx_diff);

	cout << cnt << "\n";

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}