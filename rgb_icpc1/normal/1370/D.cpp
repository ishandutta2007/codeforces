#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n, k;
int a[MX];

bool ok(int x) {
	//odd
	int j = 0;
	bool f = 1;
	for(int i = 0; i < k; i ++) {
		if (j >= n) {
			f = 0;
			break;
		}
		if (i & 1) {
			for (; j < n; j ++) if (a[j] <= x) break;
			if (j == n) {
				f = 0;
				break;
			}
		}
		j ++;
	}
	if (f) return 1;
	//even
	f = 1;
	j = 0;
	for (int i = 0; i < k; i ++) {
		if (j >= n) {
			f = 0;
			break;
		}
		if (!(i & 1)) {
			for (; j < n; j ++) if (a[j] <= x) break;
			if (j == n) {
				f = 0;
				break;
			}
		}
		j ++;
	}
	return f;
}

int main() {
	
	cin >> n >> k;
	
	vector<int> v;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	int st = 0, en = n - 1;
	while (st < en - 1) {
		int mi = (st + en) / 2;
		if (ok(v[mi])) en = mi;
		else st = mi;
	}
	while (st < n && !ok(v[st])) st ++;
	cout << v[st] << endl;
}