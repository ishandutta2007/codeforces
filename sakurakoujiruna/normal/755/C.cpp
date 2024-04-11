#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;
int p[N];

int f(int x) {
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	iota(p, p + N, 0);
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		if(f(i) != f(x))
			p[f(i)] = f(x);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		if(f(i) == i)
			cnt ++;
	cout << cnt << '\n';
	return 0;
}