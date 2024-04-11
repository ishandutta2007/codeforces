#include <bits/stdc++.h>
using namespace std;
void make(int &n){
	if (n >= 100) n-= 100;
	else if (n >= 20) n-= 20;
	else if (n >= 10) n-= 10;
	else if (n >= 5) n-= 5;
	else if (n >= 1) n-= 1;
}

signed main(){
	int n, i;
	cin >> n;
	for (i = 0; n > 0; i++, make(n));
	cout << i;
}