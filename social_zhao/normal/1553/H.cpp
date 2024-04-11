#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1 << 19;
int n, k;
int f[2][N], mxv[2][N], mnv[2][N], a[N + 5];

int main() {
	n = get(), k = get();
	int now = 0, lst = 1;
	memset(f, 0x3f, sizeof(f)), memset(mxv, -0x3f, sizeof(mxv)), memset(mnv, 0x3f, sizeof(mnv));
	for(int i = 1; i <= n; i++) {
		a[i] = get(), mnv[now][a[i]] = mxv[now][a[i]] = 0;
	}
	for(int t = 0; t < k; t++) {
		swap(now, lst);
		for(int i = 0; i < 1 << k; i++) {
			f[now][i] = min(min(f[lst][i], f[lst][i ^ (1 << t)]), mnv[lst][i ^ (1 << t)] - mxv[lst][i] + (1 << t));
			mnv[now][i] = min(mnv[lst][i], mnv[lst][i ^ (1 << t)] + (1 << t));
			mxv[now][i] = max(mxv[lst][i], mxv[lst][i ^ (1 << t)] + (1 << t));
		}
	}
	for(int i = 0; i < 1 << k; i++) printf("%d ", f[now][i]);
	return 0;
}