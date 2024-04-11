#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int t, cnt[N], mx, a[N], x, y, n, m, now[N];

int main() {
	t = get();
	for(int i = 1; i <= t; i++) a[i] = get(), mx = max(mx, a[i]), ++cnt[a[i]];
	if(t == 1 && cnt[0]) { cout << "1 1\n1 1\n"; return 0; }
	for(int i = 1; i <= mx; i++)
		if(cnt[i] < 4 * i) { x = i; break; }
	for(n = 1; n <= t; n++) {
		if(t % n) continue;
		m = t / n, y = n + m - mx - x;
		if(y < 1 || y > m) continue;
		for(int i = 0; i <= mx; i++) now[i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				++now[abs(i - x) + abs(j - y)];
		int flag = 1;
		for(int i = 0; i <= mx && flag; i++) if(now[i] != cnt[i]) flag = 0;
		if(flag) {
			cout << n << " " << m << endl;
			cout << x << " " << y << endl;
			return 0;
		}
	}
	cout << -1;
	return 0;
}