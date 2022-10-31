#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


const int mxa = 100;
int d;
int n;
vector<int> a;
vector<int> dp;


int get_d() {
	vector<int> c(mxa + 1, 0);
	for (int i = 0; i < n; ++i) {
		c[a[i]]++;
	}
	int res = 0;
	int rc = 1;
	for (int i = 1; i < mxa; ++i) {
		if(c[i] > c[res]){
			res = i;
			rc = 1;
		}
		else if (c[i] == c[res]) {
			rc += 1;
		}
	}
	d = res;
	return rc;
}


int get_mx_len(int c) {
	dp.resize(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		dp[i] = -1;
	}
	dp[n - 1] = 0;
	int s = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == d) {
			++s;
		}
		else if (a[i] == c) {
			--s;
		}
		if (dp[n - 1 + s] != -1) {
			res = max(res, i + 1 - dp[n - 1 + s]);
		}
		else {
			dp[n - 1 + s] = i + 1;
		}
	}
	return res;
}


int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x = get_d();
	if (x > 1) {
		cout << n << "\n";
	}
	else {
		int res = 0;
		for (int i = 1; i < mxa; ++i) {
			if (i != d) {
				res = max(res, get_mx_len(i));
			}
		}
		cout << res << "\n";
	}
	return 0;
}