// Problem: C. Build Permutation
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, a[N], nx[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	nx[0] = 0;
	rep(i, 1, 100000) nx[i] = nx[i-1] + (nx[i-1] * nx[i-1] < i);
	rep(i, 1, 100000) nx[i] *= nx[i];
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 0, n-1) a[i] = -1;
		int i = n - 1;
		while(i >= 0) {
			int j = nx[i] - i;
			while(a[j] == -1) {
				a[j] = nx[i] - j;
				++j;
			}
			i = j - 1;
		}
		rep(i, 0, n-1) printf("%d%c", a[i], " \n"[i==n-1]);
	}
	return 0;
}