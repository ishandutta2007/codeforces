#include <bits/stdc++.h>
using namespace std;
int n, a[1000009]; bool prime[2000009];
int main() {
	fill(prime + 2, prime + 2000005, true);
	for(int i = 2; i * i <= 2000000; i++) {
		if(!prime[i]) continue;
		for(int j = i * i; j <= 2000000; j += i) prime[j] = false;
	}
	cin >> n;
	vector<int> p; int c1 = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 1) c1++;
		else p.push_back(a[i]);
	}
	vector<int> ret = { a[0] };
	if(c1 >= 2) ret = vector<int>(c1, 1);
	// Case 1: 1's + 1 number
	for(int i : p) {
		if(prime[i + 1]) {
			vector<int> res(c1, 1);
			res.push_back(i);
			ret = res;
			break;
		}
	}
	// Case 2: 2 numbers
	bool flag1 = false;
	for(int i = 0; i < p.size() && !flag1; i++) {
		for(int j = i + 1; j < p.size() && !flag1; j++) {
			if(prime[p[i] + p[j]]) {
				if(ret.size() == 1) {
					ret = { p[i], p[j] };
					flag1 = true;
				}
			}
		}
	}
	// Case 3: 1's + 2 numbers
	bool flag2 = false;
	for(int i = 0; i < p.size() && !flag2; i++) {
		for(int j = i + 1; j < p.size() && !flag2; j++) {
			if(prime[p[i] + p[j]] && prime[1 + p[i]] && prime[1 + p[j]]) {
				if(ret.size() == 1) {
					vector<int> res(c1, 1);
					res.push_back(p[i]);
					res.push_back(p[j]);
					ret = res;
					flag2 = true;
				}
			}
		}
	}
	cout << ret.size() << endl;
	for(int i : ret) cout << i << ' ';
	return 0;
}