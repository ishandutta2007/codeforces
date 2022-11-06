// LUOGU_RID: 90900229
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int T, u, v;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &u, &v);
		if(u > v) puts("NO");
		else {
			int p = 0, q = 0;
			for(;u||v;u>>=1,v>>=1) {
				p += u & 1;
				q += v & 1;
				if(p < q) {
					puts("NO");
					goto qwq;
				}
			}
			puts("YES");
			qwq:;
		}
	}
	return 0;
}