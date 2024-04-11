#include <bits/stdc++.h>

using namespace std;

int f(int m) {
	if(m % 10 == 0)
		m /= 10;
	else
		m -= 1;
	return m;
}

signed main(){
	int n, k;
	cin >> n >> k;
    for (int i = 0; i < k; i++) {
    	n = f(n);
    } 
    cout << n;
	return 0;
}