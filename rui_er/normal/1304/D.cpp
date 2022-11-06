//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, a[N], lst;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s", &n, s+1);
		rep(i, 1, n) a[i] = n - i + 1;
		lst = 0;
		rep(i, 1, n-1) {
			if(s[i] == '<') {
				if(!lst) lst = i;
			}
			else if(lst) {
				reverse(a+lst, a+1+i);
				lst = 0;
			}
		}
		if(lst) reverse(a+lst, a+1+n);
		rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
		rep(i, 1, n) a[i] = i;
		lst = 0;
		rep(i, 1, n-1) {
			if(s[i] == '>') {
				if(!lst) lst = i;
			}
			else if(lst) {
				reverse(a+lst, a+1+i);
				lst = 0;
			}
		}
		if(lst) reverse(a+lst, a+1+n);
		rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
	}
    return 0;
}