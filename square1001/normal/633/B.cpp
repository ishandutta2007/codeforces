#include <bits/stdc++.h>
using namespace std;
int solve(int x) {
	int ret = 0;
	while(x) x /= 5, ret += x;
	return ret;
}
int n;
int main() {
	cin >> n;
	vector<int> v;
	for(int i = 0; i <= 500000; i++) {
		if(solve(i) == n) v.push_back(i);
	}
	cout << v.size() << endl;
	for(int i : v) cout << i << ' ';
	return 0;
}