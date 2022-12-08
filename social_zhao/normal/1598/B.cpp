#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, a[N][6];

int calc(int x, int y) {
	int cntx = 0, cnty = 0, cntxy = 0;
	for(int i = 1; i <= n; i++) 
		if(!a[i][x] && !a[i][y]) return 0;
		else if(!a[i][x]) cnty++;
		else if(!a[i][y]) cntx++;
		else cntxy++;
	if(min(cntx, cnty) + cntxy >= max(cntx, cnty)) return 1;
	else return 0;
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= 5; j++)
			a[i][j] = get();
	if(n & 1) return cout << "NO" << endl, void(); 
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++) {
			if(i == j) continue;
			if(calc(i, j)) return cout << "YES" << endl, void();
		}
	cout << "NO" << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}