//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	if(!(k & 1)) {
		cout << "NO\n";
		return 0;
	}
	if(k == 1){
		cout << "YES\n";
		cout << 2 << ' ' << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	cout << "YES\n";
	int n = k + 2;
	cout << 2 * n << ' ' << (n * k) << endl;
	for(int i = 1; i < n;i++){
		for(int j = i + 1; j < n;j++){
			if((i & 1) == 1 && i + 1 == j && i != 1) continue;
			cout << i << ' ' << j << '\n';
		}
		if(i > 2) cout << i << ' ' << n << '\n';
	}
	cout << n << ' ' << 2 * n << '\n';
	for(int i = 1; i < n;i++){
		for(int j = i + 1; j < n;j++){
			if((i & 1) == 1 && i + 1 == j && i != 1) continue;
			cout << i + n << ' ' << j + n<< '\n';
		}
		if(i > 2) cout << i + n << ' ' << n + n << '\n';
	}
}