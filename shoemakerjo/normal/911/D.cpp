#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define maxn 1510

int nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int m;
	cin >> m;
	int l, r;
	bool odd = false;
	int ct = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] < nums[j]) ct++;
		}
	}
	// cout << "ct   " << ct << endl;
	if (ct%2 == 1) odd = true;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		int len = r-l+1;
		int sz = (len*(len-1))/2;
		// cout << sz << endl;
		if (sz%2==1) {
			if (odd) odd = false;
			else odd = true;
		}
		if (odd) cout << "odd" << endl;
		else cout << "even" << endl;
	}
	cin >> n;
}