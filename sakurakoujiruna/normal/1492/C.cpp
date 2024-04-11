#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;

int a[N], b[N];

int main() {
	int n, m; cin >> n >> m;
	
	string s, t; cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	
	for(int i = 1; i <= n; i ++)
		if(a[i - 1] + 1 <= m && s[i] == t[a[i - 1] + 1])
			a[i] = a[i - 1] + 1;
		else
			a[i] = a[i - 1];
	
	b[n + 1] = m + 1;
	for(int i = n; i >= 1; i --)
		if(b[i + 1] - 1 >= 1 && s[i] == t[b[i + 1] - 1])
			b[i] = b[i + 1] - 1;
		else
			b[i] = b[i + 1];
	
	//~ for(int i = 1; i <= n; i ++)
		//~ cout << a[i] << ' ';
	//~ cout << '\n';
	//~ for(int i = 1; i <= n; i ++)
		//~ cout << b[i] << ' ';
	//~ cout << '\n';
	
	int ans = 0;
	int p = 0;
	for(int i = 1; i <= n; i ++) {
		p = max(p, i + 1);
		while(p + 1 <= n && a[i] + 1 >= b[p + 1])
			p ++;
		
		if(p <= n && a[i] >= 1 && b[p] <= m && a[i] + 1 == b[p]) {
			ans = max(ans, p - i);
		}
	}
	
	cout << ans << '\n';
}