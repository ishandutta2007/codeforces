#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i ++)
		if(n % i == 0) return false;
	return true;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= 1000; i ++)
		if(!check(i * n + 1)) {
			cout << i << '\n';
			break;
		}
	return 0;
}