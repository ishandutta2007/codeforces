#include <bits/stdc++.h>

using namespace std;

int main(){
	int b, k, res = 0;

	cin >> b >> k;

	for(int i = 0; i < k - 1; i++){
		int x; 

		cin >> x;

		if(b & 1){
			res += x;
		}
	}

	int x;

	cin >> x;

	res += x;

	res %= 2;

	if(!res){
		cout << "even\n";
	}
	else{
		cout << "odd\n";
	}

	return 0;
}