#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int a, b, c, d; cin >> a >> b >> c >> d;
	int e = min(a,b);
	int f = min(c,d);
	cout << e << " " << (f == e?f+1:f) << "\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}