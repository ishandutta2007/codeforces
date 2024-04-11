// Problem: CF1702B Polycarp Writes a String from Memory
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1702B
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
const int N = 2e5+5;

int T, n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		int days = 0, now = 1;
		while(now <= n) {
			++days;
			char a = 0, b = 0, c = 0;
			while(now <= n) {
				if(!a || a == s[now]) a = s[now];
				else if(!b || b == s[now]) b = s[now];
				else if(!c || c == s[now]) c = s[now];
				else break;
				++now;
			}
		}
		printf("%d\n", days);
	}
	return 0;
}