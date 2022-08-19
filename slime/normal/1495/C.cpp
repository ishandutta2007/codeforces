//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 505 /*rem*/
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
char inp[maxn][maxn];
int id(int x, int y) {
	return (x - 1) * m + y;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", inp[i] + 1);
		for (int i = 1; i <= n; i += 3)
			for (int j = 1; j <= m; j++) 
				inp[i][j] = 'X';
		for (int i = 1; i + 3 <= n; i += 3) {
			int fl = 0;
			for (int j = 1; j <= m; j++) {
				if (inp[i + 1][j] == 'X' || inp[i + 2][j] == 'X') {
					inp[i + 1][j] = inp[i + 2][j] = 'X';
					fl = 1;
					break;
				}
			}
			if (!fl) inp[i + 1][1] = inp[i + 2][1] = 'X';
		}
		if (n % 3 == 0) 
			for (int j = 1; j <= m; j++)
				if (inp[n][j] == 'X') inp[n - 1][j] = 'X';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				printf("%c", inp[i][j]);
			printf("\n");
		}
	}
	return 0;
}