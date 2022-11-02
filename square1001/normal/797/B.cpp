#include <bits/stdc++.h>
using namespace std;
int n, a[100009];
int main() {
	cin >> n;
	vector<int> v;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] & 1) v.push_back(a[i]);
		else if(a[i] >= 0) sum += a[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int ret = -1000000009;
	for(int i = 0; i < v.size(); i++) {
		sum += v[i];
		if(i % 2 == 0) ret = max(ret, sum);
	}
	cout << ret << endl;
	return 0;
}