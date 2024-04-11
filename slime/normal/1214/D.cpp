#include <bits/stdc++.h>
#define maxn 1000005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
const int md[2] = {1000000007, 998244353};
struct hs {
	int a[2];
	hs(int x) {
		a[0] = a[1] = x;
	}
	hs() {
		a[0] = a[1] = 0;
	}
	hs(int u, int v) {
		a[0] = u, a[1] = v; 
	}
	hs operator + (hs t) {
		return hs((a[0] + t.a[0]) % md[0], (a[1] + t.a[1]) % md[1]);
	}
}p[maxn], q[maxn]; 
int fl[maxn];	
int n, m;
int gt(int u, int v) {
	if (u <= 0 || u > n || v <= 0 || v > m) return 0;
	return (u - 1) * m + v;
}
char inp[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		for (int j = 1; j <= m; j++)
			if (inp[j] == '.') fl[gt(i, j)] = 0;
			else fl[gt(i, j)] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (i == 1 && j == 1) p[gt(i, j)] = hs(1);
			else if (!fl[gt(i, j)]) 
				p[gt(i, j)] = p[gt(i - 1, j)] + p[gt(i, j - 1)];
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			if (i == n && j == m) q[gt(i, j)] = hs(1);
			else if (!fl[gt(i, j)]) 
				q[gt(i, j)] = q[gt(i + 1, j)] + q[gt(i, j + 1)];
	if (p[n * m].a[0] == 0 && p[n * m].a[1] == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			if (i == n && j == m) continue;
			int fl = 0, nid = gt(i, j);
			for (int k = 0; k < 2; k++)
				if (1ll * p[nid].a[k] * q[nid].a[k] % md[k] != p[n * m].a[k]) fl = 1;
			if (!fl) {
				cout << 1 << endl;
				return 0;
			}
		}
	cout << 2 << endl;
	return 0;
} 
/*
2 1 1 5

 
*/