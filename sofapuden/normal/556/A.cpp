#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int cn = 0;
	for(char c : s){
		cn+=(c == '1');
	}
	cout << abs(2*cn-n) << "\n";
}