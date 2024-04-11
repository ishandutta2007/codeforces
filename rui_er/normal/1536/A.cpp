//LG@rui_er 
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const int N = 305;

int T, n, a[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		ll ok = 1;
		rep(i, 1, n) if(a[i] < 0) {ok = 0; break;}
		if(ok) {
			puts("YES\n101");
			rep(i, 0, 100) printf("%d%c", i, " \n"[i==100]);
		}
		else puts("NO");
	}
	return 0;
}