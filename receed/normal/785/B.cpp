#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n, m, minn=1000000001, maxn = -1, minm=1000000001, maxm = -1;
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		maxn = max(maxn, a);
		minn = min(minn, b);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		maxm = max(maxm, a);
		minm = min(minm, b);
	}
	cout << max(max(maxm - minn, maxn - minm), 0);
	return 0;
}