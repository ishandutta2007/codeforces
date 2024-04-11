#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, m, x, y; cin >> n >> m >> x >> y;
		int ans = 0;
		ans+=max(x-1,n-x);
		ans+=max(y-1,m-y);
		cout << ans << "\n";
	}
}