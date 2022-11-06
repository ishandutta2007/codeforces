// Problem: CF1698D Fixed Point Guessing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1698D
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

int T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int L, int R) {
	printf("? %d %d\n", L, R);
	fflush(stdout);
	int cnt = 0;
	rep(i, L, R) {
		int x;
		scanf("%d", &x);
		cnt += (L <= x && x <= R);
	}
	return cnt;
}
void give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int L = 1, R = n + 1;
		while(L < R) {
			int M = (L + R) >> 1;
			if(ask(L, M) & 1) R = M;
			else L = M + 1;
		}
		give(L);
	}
	return 0;
}