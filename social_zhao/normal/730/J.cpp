#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, k, sum, now, f[N * N][N];
struct Bottle { int a, b; } t[N];

int main() {
	n = get();
	for(int i = 1; i <= n; i++) t[i].a = get(), sum += t[i].a;
	for(int i = 1; i <= n; i++) t[i].b = get();
	sort(t + 1, t + 1 + n, [](Bottle x, Bottle y){ return x.b > y.b; });
	for(int i = 1; i <= n; i++) {
		now += t[i].b;
		if(now >= sum) { k = i; break; } 
	}
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = now; j >= t[i].b; j--)
			for(int l = k; l >= 1; l--)
				f[j][l] = max(f[j][l], f[j - t[i].b][l - 1] + t[i].a);
	int ans = 0;
	for(int i = sum; i <= now; i++) ans = max(ans, f[i][k]);
	printf("%d %d\n", k, sum - ans);
	return 0;
}