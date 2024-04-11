//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(!(n & 1)){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n;i++) cout << i << ' ';
	cout << endl;
	for(int i = 0; i < n;i++) cout << i << ' ';
	cout << endl;
	for(int i = 0; i < n;i++) cout << (2 * i) % n << ' ';
	return 0;
}