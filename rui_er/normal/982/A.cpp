// Problem: CF982A Row
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF982A
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
const int N = 1e3+5;

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%1d", &a[i]);
	a[0] = a[n+1] = -1;
	rep(i, 1, n) {
		if(a[i] == 0 && a[i-1] != 1 && a[i+1] != 1) return puts("No")&0;
		if(a[i] == 1 && (a[i-1] == 1 || a[i+1] == 1)) return puts("No")&0;
	}
	puts("Yes");
	return 0;
}