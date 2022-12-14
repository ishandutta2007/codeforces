#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000, inf = 0x7f7f7f7f;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

vector <int> s[maxn];

int a[maxn], n , m, b, mx;

bool same(int x) {
	int mn = inf, mx = 0;
	for (int i = 0, ed = s[x].size(); i < ed; i ++) {
		mn = min(mn, s[x][i]);
		mx = max(mx, s[x][i]);
	}
	return mn == mx && (s[x].size() != 1);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	m = read();int l = 1;
	for (int i = 1; i <= m; i ++) {
		for (b = read(); b > 0 && l <= n; l ++) 
			s[i].push_back(a[l]), b -= a[l];
		if (b != 0 || (i == m && l <= n)) return puts("NO"), 0;
	}
	for (int i = 1; i <= m ; i ++) 
		if (same(i)) return puts("NO"), 0;
	puts("YES");	
	for (int i = 1; i <= m; i ++) {
		mx = 0;
		for (int j = 0; j < s[i].size(); j ++) mx = max(mx, s[i][j]);
		
		bool flag = 0;
		
		for (int who = 0; who + 1 < s[i].size(); who ++) {
			if (mx == s[i][who] && s[i][who] > s[i][who + 1]){
				for (int j = who + 1, ed = s[i].size(); j < ed; j ++) printf("%d %c\n", i + who, 'R');
				for (int j = who; j; j --) printf("%d %c\n" , i + j, 'L');
				flag = 1;
				break;
			} 
		}
		
		if (flag) continue;
		
		for (int who = 1; who < s[i].size(); who ++) {
			if (mx == s[i][who] && s[i][who - 1] < s[i][who]){
				for (int j = who; j; j --) printf("%d %c\n" , i + j, 'L');
				for (int j = who, ed = s[i].size(); j + 1 < ed; j ++) printf("%d %c\n", i, 'R');	
				break;
			}
		}
	}
	return 0;
}