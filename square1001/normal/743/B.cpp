#include <bits/stdc++.h>
using namespace std;
int n; long long m;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		if(m % (1LL << i)) {
			cout << i << endl;
			break;
		}
	}
}