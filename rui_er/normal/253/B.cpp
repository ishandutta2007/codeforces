// Problem: CF253B Physics Practical
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF253B
// Memory Limit: 250 MB
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

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	int L = 1, R = 1, ans = 0;
	while(L <= n) {
		while(R <= n && a[R] <= 2 * a[L]) ++R;
		chkmax(ans, R-L);
		++L;
	}
	printf("%d\n", n-ans);
	return 0;
}