#include <bits/stdc++.h>
using namespace std;

const int N = 511;
int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, x; cin >> n >> x;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int l = count_if(a, a + n, [&](int t){ return t < x; });
	int g = count_if(a, a + n, [&](int t){ return t > x; });
	int m = n;
	if(!count(a, a + m, x))
		m ++;
	while(l > (m + 1) / 2 - 1) {
		m ++; g ++;
	}
	while(g > m - (m + 1) / 2) {
		m ++; l ++;
	}
	cout << m - n << '\n';
	return 0;
}