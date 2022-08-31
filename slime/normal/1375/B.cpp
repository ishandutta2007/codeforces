//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n, m;
int a[305][305];
int fl[305][305];
bool chk(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}
int mv[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		int re = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				int tot = 0;
				for (int k = 0; k < 4; k++) {
					int ex = i + mv[k][0], ey = j + mv[k][1];
					if (chk(ex, ey)) tot++;
				}
				if (tot < a[i][j]) re = 0;
				a[i][j] = tot;
			}
		if (!re) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				printf("%d ", a[i][j]);
			printf("\n");		
		}
	}
	}
	return 0;
}