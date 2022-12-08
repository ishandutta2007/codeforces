#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
} 

const int N = 2e5 + 5;
int n, a[N];
map<int, int> f;

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	f[a[1] - 1] = 0;
	for(int i = 1; i < n; i++) {
		for(map<int, int>::iterator it = f.lower_bound(a[i + 1]); it != f.end(); f.erase(it++)) {
			int j = it -> first, v = it -> second;
			f[j % a[i + 1]] = max(f[j % a[i + 1]], v + i * (j - j % a[i + 1]));
			f[a[i + 1] - 1] = max(f[a[i + 1] - 1], v + i * ((j + 1) / a[i + 1] * a[i + 1] - a[i + 1]));
		}
	}
	int mx = 0;
	for(map<int, int>::iterator it = f.begin(); it != f.end(); ++it) mx = max(mx, n * (it -> first) + (it -> second));
	cout << mx;
	return 0;
}