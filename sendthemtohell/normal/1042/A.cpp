#include "bits/stdc++.h"

#define all(v) (v).begin(),(v).end()

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int mx = *max_element(all(v)) + m;
	int mn = 0;
	int kek = m - (n*(mx - m) - accumulate(all(v),0));
	if(kek <= 0) mn = mx - m;
	else mn = mx - m + (kek + n - 1) / n;
	cout << mn << " " << mx << endl;
}