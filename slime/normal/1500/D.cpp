//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1505 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
const int q = 12;
inline char nc() {
	static char buf[100000],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int red() {
	int x=0; char s=nc();
	while(s<'0'||s>'9') s=nc();
	while(s>='0'&&s<='9') x=((x+(x<<2))<<1)+s-'0',s=nc();
	return x;
}
int rc() {
	char s=nc();
	while(s!='C'&&s!='R'&&s!='Q') s=nc();
	return s;
}
int a[maxn][maxn], e[maxn][maxn][q], c[maxn][maxn][q];
int h[3][q], f[3][q];
int fl[maxn * maxn];
int d[maxn];
int main() {
	int n, qq;
	n = red(), qq = red();
//	cin >> n >> qq;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			a[i][j] = red();
	for (int j = n; j >= 1; j--)
		for (int k = n; k >= 1; k--) {
			e[j][k][1] = 1, c[j][k][1] = a[j][k];
			if (j == n || k == n) {
				for (int u = 2; u < q; u++)
					e[j][k][u] = 2, c[j][k][u] = n * n + u;
				continue;
			}
			fl[a[j][k]] = 1;
			int p[3] = {1, 1, 1};
			for (int s = 0; s < q; s++)
				h[0][s] = e[j + 1][k][s], 
				f[0][s] = c[j + 1][k][s], 
				h[1][s] = e[j][k + 1][s], 
				f[1][s] = c[j][k + 1][s], 
				h[2][s] = e[j + 1][k + 1][s], 
				f[2][s] = c[j + 1][k + 1][s];
			int tot = 1;
			while (1) {
				int mn = 0, ms = maxn;
				for (int i = 0; i < 3; i++)
					if (chkmin(ms, h[i][p[i]])) mn = i;
				int i = mn;
				int uc = f[i][p[i]];
				if (!fl[uc]) {
					fl[uc] = 1;
					tot++;
					e[j][k][tot] = ms + 1;
					c[j][k][tot] = uc;
					if (tot > qq) break;
				}
				p[i]++;
			}
			for (int u = 0; u < q; u++)
				fl[c[j][k][u]] = 0;
		}
	for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
			d[1]++, d[e[j][k][qq + 1]]--;
	for (int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
		printf("%d\n", d[i]);
	}
	return 0;
}