//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 105 /*rem*/
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
int n;
int fl[maxn][maxn]; 
int as[maxn][maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if ((i + j) % 2) as[i][j] = 1;
			else as[i][j] = 2;
		}
	for (int x = 1; x <= n * n; x++) {
		int r;
		cin >> r;
		int p[2] = {0, 0};
		int f = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (fl[i][j]) continue;
				if (f) break;
				if (as[i][j] != r) {
					cout << as[i][j] << ' ' << i << ' ' << j << endl;
					fl[i][j] = as[i][j];
					fflush(stdout);
					f = 1;
					break;
				}
				p[0] = i, p[1] = j;
			}
		if (!f) {
			fl[p[0]][p[1]] = 3;
			cout << 3 << ' ' << p[0] << ' ' << p[1] << endl;
			fflush(stdout);
		}
	}
	return 0;
}