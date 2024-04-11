#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		if(max(c,a) <= min(d,b)){
			cout << max(c,a) << '\n';
		}
		else{
			cout << a+c << '\n';

		}

	}
}