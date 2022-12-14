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
#define N 10

int n, q;
char s[N];
map<string, int>M, A, B;
char f[10010][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", f[i]);
		int l = strlen(f[i]);
		M.clear();
		for (int j = 0; j < l; j ++) {
			string emp = "";
			for (int k = j; k < l; k ++) {
				emp += f[i][k];
				M[emp] = 1;
				A[emp] = i;
			}
		}
		for (auto x:M) B[x.first] ++;
	}
	scanf("%d", &q);
	while (q --) {
		scanf("%s", s);
		printf("%d ", B[s]);
		if (!B[s]) printf("-\n");
		else printf("%s\n", f[A[s]]);
	}
    return 0;
}