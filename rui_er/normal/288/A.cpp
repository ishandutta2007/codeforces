//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e6+5; 

int n, k, tot; char s[N], now;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	if(n < k || k == 1 && n > 1) return puts("-1")&0;
	now = 'a' + k - 1;
	while(now > 'b') s[tot++] = now--;
	now = 'a';
	per(i, n-1, tot) {
		s[i] = now;
		now ^= 'a' ^ 'b';
	}
	s[n] = '\0';
	reverse(s, s+n);
	printf("%s\n", s);
	return 0;
}