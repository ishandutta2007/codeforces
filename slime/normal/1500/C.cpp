//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1605 /*rem*/
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
int a[maxn][maxn], b[maxn][maxn];
ll ah[maxn], bh[maxn];
int fl[maxn];
int n, m;
int d[maxn];
int ff[maxn];

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

int main() {
	scanf("%d%d", &n, &m);
	int base = 1519;
	for (int i = 1; i <= n; i++) {
		ah[i] = 0;
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), 
			ah[i] = ah[i] * base + a[i][j];
		a[i][m + 1] = i;
	}
	for (int i = 1; i <= n; i++) {
		bh[i] = 0;
		for (int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]), 
			bh[i] = bh[i] * base + b[i][j];
		}
		for (int k = 1; k <= n; k++) {
			if (fl[k]) continue;
			if (bh[i] == ah[k]) {
				b[i][m + 1] = k;
				fl[k] = 1;
				break;
			}
		}
		if (!b[i][m + 1]) {
			cout << -1 << endl;
			return 0;
		}
	}
	m += 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < n; j++)
			if (b[j][i] > b[j + 1][i]) d[i] += 1;
	memset(fl, 0, sizeof(fl));
	vi res;
	for (int u = 1; u <= m; u++) {
		int pl = 0;
		for (int i = 1; i <= m; i++) {
			if (fl[i]) continue;
			if (d[i] == 0) pl = i;
		}
		if (!pl) {
			cout << -1 << endl;
			return 0;
		}
		fl[pl] = 1;
		if (pl == m) {
			reverse(res.begin(), res.end());
			cout << res.size() << endl;
			for (auto v : res) cout << v << ' ';
			return 0; 
		} 
		res.pb(pl);
		for (int i = 1; i < n; i++) 
			if ((b[i][pl] < b[i + 1][pl]) && (!ff[i])) {
				ff[i] = 1;
				for (int j = 1; j <= m; j++) 
					if (b[i][j] > b[i + 1][j]) d[j]--;
			}
	}
	return 0;
}