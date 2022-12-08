#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
int n, k, f[N][N], pre[N][N]; // n  m  
int top = 0, ans = 0, bin[N];
queue<int> shit;

void solve(int step, int now) {
	if(!step) return;
	solve(step - 1, now - (k - pre[step][now]) + pre[step][now]);
	cout << "? ";
	for(int i = 1; i <= pre[step][now]; i++) 
		cout << bin[top] << " ", shit.push(bin[top]), top--;
	for(int i = 1; i <= k - pre[step][now]; i++) 
		cout << shit.front() << " ", bin[++top] = shit.front(), shit.pop();
	cout << endl;
	cout.flush();
	int res;
	cin >> res;
	ans ^= res;
}

int main() {
	n = get(), k = get();
	f[0][0] = 1;
	for(int i = 0; i <= 500; i++)
		for(int j = 0; j <= n; j++) {
			if(!f[i][j]) continue;
			for(int p = 0; p <= min(k, j); p++) 
				if(k - p <= n - j) f[i + 1][j - p + (k - p)] = 1, pre[i + 1][j - p + (k - p)] = p; 
		}
	for(int i = 1; i <= n; i++) shit.push(i);
	for(int i = 1; i <= 500; i++) if(f[i][n]) { solve(i, n); cout << "! " << ans << endl; cout.flush(); return 0; }
	cout << -1 << endl; cout.flush();
	return 0;
}