#include <bits/stdc++.h>
using namespace std;

//const int N = 100;
//int a[N];

//int main() {
	//ios :: sync_with_stdio(0);
	
	//for(int n = 3; n <= 16; n ++) {
		//fill(a, a + N, 0);
		//for(int i = 1; i <= n; i ++)
			//a[2 * i - 1] = i;
		//for(int j = 2 * n - 1; j > n; j --) if(a[j]) {
			//for(int k = j - 1; ; k --) if(!a[k]) {
				//swap(a[j], a[k]);
				//break;
			//}
		//}
		//for(int i = 1; i <= n; i ++)
			//cout << a[i] << ' ';
		//cout << '\n';
	//}
//}

using ll = long long;

ll solve(ll n, ll x) {
	//cout << n << ' ' << x << '\n';
	if(x & 1)
		return x / 2 + 1;
	if(n & 1)
		return solve(n - (n + 1) / 2 + 1, x / 2 + 1) + (n + 1) / 2 - 1;
	return solve(n / 2, x / 2) + n / 2;
}

int main() {
	ios :: sync_with_stdio(0);
	ll n; int q; cin >> n >> q;
	
	while(q --) {
		ll x; cin >> x;
		cout << solve(n, x) << '\n';
	}
}