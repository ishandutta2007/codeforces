#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, q;
string s[N];
vector<int> sum[N];

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 0; i <= n; i++) sum[i].resize(m + 1);
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			if(s[i][j] == 'X' && s[i + 1][j - 1] == 'X') ++sum[i][j];
//	for(int i = 1; i <= n; i++, cout << endl)
//		for(int j = 1; j <= m; j++)
//			cout << sum[i][j] << " ";
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] += sum[i - 1][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] += sum[i][j - 1];
	int q = get();
	for(int i = 1; i <= q; i++) {
		int l = get(), r = get();
		int cnt = sum[n][r - 1] - sum[n][l - 1];
		if(cnt) cout << "NO" << endl;
		else cout << "YES" << endl;
	} 
	return 0;
}