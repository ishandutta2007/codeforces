#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n, m, a, b; cin >> n >> m >> a >> b;
	cout << min(n*a, min((n/m*b+n%m*a),(n+m-1)/m*b)) << "\n";
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	solve();
		
	return 0;
}