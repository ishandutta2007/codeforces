#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
char s[2][N];
int n;

void solve()  {
	n = get();
	scanf("%s", s[0] + 1), scanf("%s", s[1] + 1);
	if(s[0][1] == '1' || s[1][n] == '1') return cout << "NO" << endl, void();
	for(int i = 1; i <= n; i++) if(s[0][i] == '1' && s[1][i] == '1') return cout << "NO" << endl, void();
	cout << "YES" << endl;
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}