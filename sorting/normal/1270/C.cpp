#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	long long lhs = 0ll, rhs = 0ll;
	for(int i = 0; i < n; ++i){
		long long a;
		cin >> a;

		lhs += a;
		rhs ^= a;
	}

	long long first = (1ll << 55ll);
	if(lhs & 1ll)
		++first;

	cout << 3ll << "\n";
	cout << first << " ";

	lhs += first;
	rhs ^= first;

	rhs *= 2ll;
	long long num = (rhs - lhs) / 2ll;
	cout << num << " " << num << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}