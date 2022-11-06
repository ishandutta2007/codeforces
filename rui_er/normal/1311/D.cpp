// Problem: CF1311D Three Integers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1311D
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

int T, a, b, c;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &a, &b, &c);
		int ans = 2147483647, A = 0, B = 0, C = 0;
		rep(i, 1, 2*c) {
			for(int j=i;j<=2*c;j+=i) {
				for(int k=j;k<=2*c;k+=j) {
					int diff = abs(i - a) + abs(j - b) + abs(k - c);
					if(diff < ans) {
						ans = diff;
						A = i;
						B = j;
						C = k;
					}
				}
			}
		}
		printf("%d\n%d %d %d\n", ans, A, B, C);
	}
	return 0;
}