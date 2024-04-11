// Problem: CF1186D Vus the Cossack and Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1186D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, b[N];
double a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lf", &a[i]);
	rep(i, 1, n) b[i] = floor(a[i]);
	int sum = accumulate(b+1, b+1+n, 0);
	rep(i, 1, n) {
		if(!sum) break;
		if(floor(a[i]) != ceil(a[i])) ++b[i], ++sum;
	}
	rep(i, 1, n) printf("%d\n", b[i]);
	return 0;
}