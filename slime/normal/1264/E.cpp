
#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int ans;
int d[maxn];
int tp[maxn][maxn];
int fl[maxn][maxn];
int mx[maxn][maxn], ch[maxn][maxn];
int n, m;
int sqr(int a) {
	return a * a;
}
int main() {
	srand(12345);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int nt = 1;
		if (u > v) 
			swap(u, v), 
			nt = 0;
		fl[u][v] = 1;
		tp[u][v] = nt;
	}
	ans = 1e9;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			if (!fl[i][j]) continue;
			ch[i][j] = 1;
			if (tp[i][j]) d[j]++;
			else d[i]++;
		}
	d[n + 1] = 1e9;
	while (1) {
		int nu = 0, nv = n + 1;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (ch[i][j]) continue;
				else {
					int rr = i, tt = j;
					if (d[rr] < d[tt]) swap(rr, tt);
					if ((d[tt] < d[nv]) || (d[tt] == d[nv] && d[rr] > d[nu]))	
						nu = rr, nv = tt;
				}
		if (nu == 0) break;
		else {
			int rr = nu, tt = nv;
			d[tt]++;
			if (rr < tt) tp[rr][tt] = 1, ch[rr][tt] = 1;
			else tp[tt][rr] = 0, ch[tt][rr] = 1;
		}
	}	
	int num = 0;
	while (1.0 * clock() / CLOCKS_PER_SEC < 0.9) {
	
		bool ch = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (fl[i][j]) continue;
				else {
					if (tp[i][j]) d[j]--;
					else d[i]--;
					int c[2] = {sqr(d[i] + 1) + sqr(d[j]), sqr(d[j] + 1) + sqr(d[i])};
					int ntp = tp[i][j];
					if (c[ntp] > c[ntp ^ 1]) {
						tp[i][j] ^= 1;
						ch = 1;
					}
					if (tp[i][j]) d[j]++;
					else d[i]++;
				}
			}
		if (!ch) {
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++) {
					if (fl[i][j]) continue;
					else {
						if (tp[i][j]) d[j]--;
						else d[i]--;
						int c[2] = {sqr(d[i] + 1) + sqr(d[j]), sqr(d[j] + 1) + sqr(d[i])};
						int ntp = tp[i][j];
						if (c[ntp] > c[ntp ^ 1]) 
							tp[i][j] ^= 1;
						if (c[ntp] == c[ntp ^ 1]) {
							if (rand() % 2)	
								tp[i][j] ^= 1;
						}
						if (tp[i][j]) d[j]++;
						else d[i]++;
					}
				}
		}
	}	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			mx[i][j] = tp[i][j];
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cur = mx[i][j];
			if (j < i) cur = 1 - mx[j][i];
			printf("%d", cur);
		}
		printf("\n"); 
	} 
	return 0;
}
/*
CHHOCH
*/