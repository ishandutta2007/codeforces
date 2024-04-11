#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	while(n--){
		long long k, x;

		cin >> k >> x;

		cout << (k-1)*9 + x << "\n";
	}

	return 0;
}