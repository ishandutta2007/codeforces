#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n; cin >> n;
	if(n % 2 == 1){
		cout << 9 << " " << n - 9 << "\n";
	}
	else{
		cout << 4 << " " << n - 4 << "\n";
	}
}