#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, k, r, c; cin >> n >> k >> r >> c;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(((r-i)+n)%k == ((c-j)+n)%k)cout << 'X';
			else cout << '.';
		}
		cout << '\n';
	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}