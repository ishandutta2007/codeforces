#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 1e9 + 7;
int n, a[N], cnt[N], sum, ok[N], ans;
vector<int> son[N];

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 2, fa; i <= n; i++) fa = get(), son[fa].push_back(i);
	for(int i = n; i >= 1; i--) 
		for(auto j : son[i]) a[i] += a[j];
	sum = a[1];
	for(int i = 1; i <= n; i++) {
		int g = __gcd(sum, a[i]);
		if(sum / g <= n) ++cnt[sum / g];
	}
	for(int i = n; i >= 1; i--)
		for(int j = i + i; j <= n; j += i)
			cnt[j] += cnt[i];
	for(int i = 1; i <= n; i++) ok[i] = cnt[i] == i;
	for(int i = n; i >= 1; i--) {
		if(!ok[i]) continue;
		for(int j = i + i; j <= n; j += i)
			ok[i] = (ok[j] + ok[i]) % P;
	}
	cout << ok[1] << endl;
	return 0;
}