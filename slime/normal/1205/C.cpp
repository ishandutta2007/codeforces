#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int chk(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	fflush(stdout);
	int r = 0;
	cin >> r;
	return r;
}
int a[maxn][maxn];
int main() {
	int n;
	cin >> n;
	a[1][1] = 1;
	for (int j = 3; j <= n; j++)
		if (chk(1, j - 2, 1, j)) a[1][j] = a[1][j - 2];
		else a[1][j] = a[1][j - 2] ^ 1;
	for (int i = 2; i <= n; i++)
		for (int j = n; j >= 1; j--) {
			if (i == n && j == n) a[i][j] = 0;
			else {
				if (j >= 2)
					if (chk(i - 1, j - 1, i, j)) a[i][j] = a[i - 1][j - 1];
					else a[i][j] = a[i - 1][j - 1] ^ 1;
				else 
					if (chk(i, j, i, j + 2)) a[i][j] = a[i][j + 2];
					else a[i][j] = a[i][j + 2] ^ 1; 
			}
		}
	int ed = 0;
	for (int i = 1; i <= n; i += 2) {
		if (a[i][i] == 1 && a[i + 2][i + 2] == 0) {
			if (chk(i, i + 1, i + 2, i + 2))
				ed = a[i][i + 1];
			else if (chk(i, i, i + 1, i + 2))
				ed = a[i + 1][i + 2] ^ 1;
			else {
				if (a[i][i + 1] == a[i + 1][i + 2]) 
					ed = a[i][i + 1] ^ a[i][i + 2] ^ 1;
				else
					if (a[i][i + 2] == 0)
						ed = a[i + 1][i + 2];
					else ed = a[i][i + 1] ^ 1; 
			} 
			break;
		}
	}
	cout << "!" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i + j) & 1) a[i][j] ^= ed;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}