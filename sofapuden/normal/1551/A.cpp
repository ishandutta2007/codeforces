#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		cout << x/3 + (x%3 == 1) << ' ' << x/3 + (x%3 == 2) << '\n';

	}
}