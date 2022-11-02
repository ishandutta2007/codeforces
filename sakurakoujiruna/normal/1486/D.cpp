#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;

int a[N];
int b[N];
int suf[N];
int suf_min[N];

bool check(int n, int k, int m) {
	for(int i = n; i >= 1; i --) {
		b[i] = (a[i] >= m ? 1 : -1);
		suf[i] = suf[i + 1] + b[i];
		
		suf_min[i] = min(suf[i], suf_min[i + 1]);
	}
	
	for(int i = 1; i + k - 1 <= n; i ++)
		if(suf[i] - suf_min[i + k] > 0)
			return 1;
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	
	
	int l = 1, r = n + 1;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(check(n, k, m))
			l = m;
		else
			r = m;
	}
	
	cout << l << '\n';
}