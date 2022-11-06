// Problem: CF1650D Twist the Permutation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1650D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 2e3+5;

int T, n, a[2][N];
stack<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[0][i]);
		per(i, n, 1) {
			int pos = 0;
			rep(j, 1, i) if(a[0][j] == i) {pos = j; break;}
			ans.push(pos%i);
			rep(j, 1, i) a[1][j] = a[0][(j+pos-1)%i+1];
			swap(a[0], a[1]);
		}
		while(!ans.empty()) {printf("%d ", ans.top()); ans.pop();}
		puts("");
	}
	return 0;
}