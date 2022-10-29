#include<bits/stdc++.h>

using namespace std;

int main(){
	char a, b; cin >> a >> b;
	int x = 0;
	x+=(a=='a');
	x+=(a=='h');
	x+=(b=='1');
	x+=(b=='8');
	if(x == 2)cout << 3;
	else if(x)cout << 5;
	else cout << 8;
	cout << "\n";
}