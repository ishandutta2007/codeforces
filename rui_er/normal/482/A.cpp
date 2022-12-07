// LUOGU_RID: 96165777
// Problem: CF482A Diverse Permutation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF482A
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

int n, k;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	int L = 1, R = k + 1, cnt = 0;
	while(cnt++ <= k) {
		printf("%d ", L++);
		if(cnt++ <= k) printf("%d ", R--);
	}
	rep(i, k+2, n) printf("%d ", i);
	return 0;
}