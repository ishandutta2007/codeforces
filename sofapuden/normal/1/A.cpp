#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	ll x, y, n; cin >> x >> y >> n;
	x = x/n +(x%n > 0 ? 1 : 0);
	y = y/n +(y%n > 0 ? 1 : 0);
	cout << x*y << "\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	solve();
		
	return 0;
}