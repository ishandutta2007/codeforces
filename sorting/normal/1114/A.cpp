#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y, z;
	int a, b, c;

	cin >> x >> y >> z;
	cin >> a >> b >> c;

	if(a < x){
		cout << "NO\n";

		return 0;
	}
	if(a + b < x + y){
		cout << "NO\n";

		return 0;
	}
	if(a + b + c < x + y + z){
		cout << "NO\n";

		return 0;
	}

	cout << "YES\n";

	return 0;
}