//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, m, s[N<<1];

int main() {
	scanf("%d", &T);
	while(T--) {
		int _ = 0; fil(s, 0);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) {int x; scanf("%d", &x); s[i+j] ^= x;}
		rep(i, 2, n+m) if(s[i]) {puts("Ashish"); _ = 1; break;}
		if(!_) puts("Jeel");
	}
	return 0;
}