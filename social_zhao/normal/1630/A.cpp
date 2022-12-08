#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, k;

void solve() {
	n = get(), k = get();
	if(k == n - 1) {
		if(n == 4 || n == 2) return cout << -1 << endl, void();
		cout << n - 1 << " " << n - 2 << endl;
		cout << n / 2 - 1 << " " << 1 << endl;
		cout << n / 2 << " " << 0 << endl;
		for(int i = 1; i < n - 1; i++) {
			if(i != n - 1 && i != n - 2 && i != n / 2 - 1 && i != 1 && i != 1 && i != 0 && (i < ((n - 1) ^ i)))
				cout << i << " " << ((n - 1) ^ i) << endl;
		}
		return;
	} 
	int base = n - 1;
	cout << 0 << " " << (base ^ k) << endl;
	if(k != 0)cout << k << " " << base << endl;
	for(int i = 1; i < n - 1; i++) {
		if(i != k && (i != (base ^ k)) && (i < (base ^ i))) cout << i << " " << (base ^ i) << endl;
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}