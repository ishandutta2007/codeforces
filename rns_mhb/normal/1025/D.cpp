#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const double pi = 3.1415926535897932384626433832795028841971l;

#define N 707

int n, a[N];
bool L[N][N], R[N][N], ok[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) ok[i][j] = ok[j][i] = (__gcd(a[i], a[j]) > 1);
	for (int i = 1; i <= n; i ++) ok[0][i] = ok[i][0] = 1;
	for (int i = 0; i <= n; i ++) ok[i][n+1] = ok[n+1][i] = 1;
	for (int l = n; l >= 1; l --) {
		R[l][l-1] = 1;
		for (int r = l; r <= n; r ++) {
			L[r+1][r] = 1;
			for (int m = l; m <= r; m ++) if (ok[l-1][m]) {
				if (R[l][m-1] && L[m+1][r]) {
					L[l][r] = 1;
					break;
				}
			}
			for (int m = l; m <= r; m ++) if (ok[m][r+1]) {
				if (R[l][m-1] && L[m+1][r]) {
					R[l][r] = 1;
					break;
				}
			}
		}
	}
	if (L[1][n]) puts("YES");
	else puts("NO");
	return 0;
}