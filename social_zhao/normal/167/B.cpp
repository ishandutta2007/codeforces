#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 205;
int n, l, k;
double f[N][N][N], ans = 0;
struct Node { int a; double p; } a[N];

int main() {
	n = get(), l = get(), k = get();
	for(int i = 1; i <= n; i++) a[i].p = get() / 100.0;
	for(int i = 1; i <= n; i++) a[i].a = get();
	f[0][0][min(k, n)] = 1;
	sort(a + 1, a + 1 + n, [](Node x, Node y) { return x.a > y.a; });
	for(int i = 0; i < n; i++) //  i  
		for(int j = 0; j <= i; j++) //  j 
			for(int w = 0; w <= n; w++) { //  w
				if(w + a[i + 1].a >= 0) f[i + 1][j + 1][min(w + a[i + 1].a, n)] += f[i][j][w] * a[i + 1].p; // 
				f[i + 1][j][w] += f[i][j][w] * (1.0 - a[i + 1].p); //  
			} 
	for(int i = l; i <= n; i++)
		for(int w = 0; w <= n; w++)
			ans += f[n][i][w];
	printf("%.10lf", ans);
	return 0;
}