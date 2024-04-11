#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n;
char c, s[N];

void solve() {
	n = get(), cin >> c, cin >> s + 1;
	int flag = 1;
	for(int i = 1; i <= n; i++) flag &= s[i] == c;
	if(flag) return cout << 0 << endl, void();
	for(int i = 1; i <= n; i++) {
		flag = 1;
		for(int j = i; j <= n; j += i) flag &= (s[j] == c);
		if(flag) return cout << 1 << endl << i << endl, void();
	}
	cout << 2 << endl << n << " " << n - 1 << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}