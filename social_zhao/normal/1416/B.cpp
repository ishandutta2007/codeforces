#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e4 + 5;
int n, a[N], sum;

void solve() {
	n = get(), sum = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), sum += a[i];
	if(sum % n) { cout << -1 << endl; return; }
	cout << 3 * n - 3 << endl;
	for(int i = 2; i <= n; i++) {
		int rem = ((i - a[i]) % i + i) % i;
		cout << 1 << " " << i << " " << rem << endl;
		cout << i << " " << 1 << " " << (a[i] + rem) / i << endl;
	}
	for(int i = 2; i <= n; i++) cout << 1 << " " << i << " " << sum / n << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}