// LUOGU_RID: 96471808
// Problem: CF301A Yaroslav and Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF301A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 205;

int n, a[N], neg, mn = 2147483647, sum = 0;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, 2*n-1) {
		scanf("%d", &a[i]);
		neg += a[i] < 0;
		chkmin(mn, abs(a[i]));
		sum += abs(a[i]);
	}
	if(!(neg & 1) || (n & 1)) printf("%d\n", sum);
	else printf("%d\n", sum-2*mn);
	return 0;
}