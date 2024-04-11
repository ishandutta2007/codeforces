#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, ans, f[N][N][2];
struct Point { int a, l; } p[N];

int qmax(int &x, int y) { x = max(x, y); }

int main() {
	n = get(); 
	for(int i = 1; i <= n; i++) p[i].a = get(), p[i].l = get();
	sort(p + 1, p + 1 + n, [](Point a, Point b) { return a.a < b.a; });
	p[0].a = -1e8, p[0].l = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k < 2; k++) {
				ans = max(ans, f[i][j][k]);
				int nowr = p[j].a + k * p[j].l, mxr = -1e9, mxi, mxk;
				for(int x = i + 1; x <= n; x++) {
					for(int z = 0; z < 2; z++) {
						int nxtr = p[x].a + z * p[x].l;
						if(nxtr > mxr) mxr = nxtr, mxi = x, mxk = z;
						qmax(f[x][mxi][mxk], f[i][j][k] + min(p[x].l, nxtr - nowr) + mxr - nxtr);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}