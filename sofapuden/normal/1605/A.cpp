#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a[3];
		for(auto &x : a)cin >> x;
		cout << min({1,abs((a[0]+a[1]-2*a[2])%3),abs((a[1]+a[2]-2*a[0])%3),abs((a[2]+a[0]-2*a[1])%3)}) << '\n';


	}
}