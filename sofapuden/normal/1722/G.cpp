#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int xo = (1<<30) | (1<<29);
	cout << (1<<30) << ' ' << (1<<29) << ' ';
	for(int i = 2; i < n-1; ++i){
		xo^=i;
		cout << i << ' ';
	}
	cout << xo << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}