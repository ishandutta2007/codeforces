#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x = 1;
	int y; cin >> y;
	while(x <= y){
		x<<=1;
	}
	if(y == x-1){
		for(int i = 3; i <= sqrt(y); ++i){
			if(!(y%i)){
				cout << y/i << '\n';
				return;
			}
		}
		cout << 1 << '\n';
		return;
	}
	cout << x-1 << '\n';

}

int main(){
	int q; cin >> q;
	while(q--){
		solve();
	}
}