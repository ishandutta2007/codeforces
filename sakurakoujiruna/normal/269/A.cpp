#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
typedef long long ll;

int k[N], a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> k[i] >> a[i];
	int m = *max_element(k, k + n);
	for(int i = 0; i < n; i ++)
		for(ll t = 1; t < a[i]; t *= 4) k[i] ++;
	cout << max(*max_element(k, k + n), m + 1) << '\n';
	return 0;
}