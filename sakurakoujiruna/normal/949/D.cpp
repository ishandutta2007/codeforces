#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;
int a[N], c[N];

int ct[N];

int n, d, b;
bool check(int mid) {
	int m = (n + 1) / 2;
	int l = min(m + 1, mid + 1);
	int r = max(m, n - mid);
	
	//cout << "------\n";
	//cout << mid << ' ' << l << ' ' << r << '\n';
	
	for(int i = 1; i <= n; i ++)
		c[i] = a[i];
	int p = 1;
	for(int i = l; i <= r; i ++) {
		int t = b;
		while(t && p <= n) {
			if((abs(i - p) + d - 1) / d <= ct[i] && c[p]) {
				int u = min(t, c[p]);
				t -= u;
				c[p] -= u;
			} else
				p ++;
		}
		if(t) return 0;
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> d >> b;
	
	for(int i = 1; i <= n; i ++)
		ct[i] = min(i, n - i + 1);
	
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	
	int left = 0, right = n + 1;
	while(left + 1 < right) {
		int mid = (left + right) / 2;
		if(check(mid - 1))
			right = mid;
		else
			left = mid;
	}
	cout << left << '\n';
}