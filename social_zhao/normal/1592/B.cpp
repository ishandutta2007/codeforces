#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, x, a[N], b[N], top;

void solve() {
	n = get(), x = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int l = max(1, n - x + 1), r = min(n, x);
	if(l > r) return cout << "YES" << endl, void();
	for(int i = l + 1; i <= r; i++) 
		if(a[i] < a[i - 1]) return cout << "NO" << endl, void();
	top = 0;
	for(int i = 1; i < l; i++) b[++top] = a[i];
	for(int i = r + 1; i <= n; i++) b[++top] = a[i];
	sort(b + 1, b + 1 + top);
	if(!top) return cout << "YES" << endl, void();
	else {
		int mid = top / 2;
		if(b[top / 2] <= a[l] && b[top / 2 + 1] >= a[r]) return cout << "YES" << endl, void();
		else cout << "NO" << endl, void();
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}