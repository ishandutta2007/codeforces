#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, x, y; cin >> n >> x >> y;
	if(x < y)swap(x,y);
	if(!x || y || (n-1)%x){
		cout << -1 << '\n';
		return;
	}
	for(int i = 0; i < (n-1)/x; ++i){
		for(int j = 0; j < x; ++j){
			cout << x*i+2 << ' ';
		}
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}