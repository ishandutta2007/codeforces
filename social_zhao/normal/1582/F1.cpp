#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, S = 1025;
int n, a[N], f[N][S], bin[N], top;

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < S; j++) f[i][j] = f[i - 1][j];
		f[i][a[i]] = min(f[i][a[i]], a[i]);
		for(int j = 0; j < S; j++) if(f[i - 1][j] < a[i]) f[i][j ^ a[i]] = min(f[i][j ^ a[i]], a[i]);
	}
	for(int i = 0; i < S; i++) if(f[n][i] < 0x3f3f3f3f) bin[++top] = i;
	cout << top << endl;
	for(int i = 1; i <= top; i++) cout << bin[i] << " ";
	return 0;
}