#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, x, y; cin >> a >> b >> x >> y;
		cout << max({(x)*b, a*(y), (a-x-1)*b, a*(b-y-1)}) << "\n";	
	}
}