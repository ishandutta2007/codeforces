#include<bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, c; cin >> a >> b >> c;
	if(abs(b-c)+c < a){
		cout << 2 << '\n';
	}
	else if(a < abs(b-c)+c){
		cout << 1 << '\n';
	}
	else{
		cout << 3 << '\n';
	}

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}