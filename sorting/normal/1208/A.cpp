#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, n;
	int ans = 0;

	cin >> a >> b >> n;

	for(int i = 0; i < 31; ++i){
		bool ax = (1 << i) & a;
		bool bx = (1 << i) & b;


		if(!ax && !bx){
			continue;
		}

		int zero = 2;

		if(!ax){
			zero = 0;
		}
		if(!bx){
			zero = 1;
		}

		if((n % 3) != zero){
			ans += (1 << i);
		}
	}

	cout << ans << "\n";
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