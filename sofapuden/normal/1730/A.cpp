#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){

	int n, c; cin >> n >> c;
	map<int,int> M;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		M[x]++;
	}
	int ans = 0;
	for(auto x : M)ans+=min(x.second,c);
	cout << ans << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();
}