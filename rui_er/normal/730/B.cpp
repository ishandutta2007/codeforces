//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 55;

int T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char s[2];
	scanf("%s", s);
	return s[0] == '<' ? -1 : s[0] == '>' ? 1 : 0;
}
void give(int x, int y) {
	printf("! %d %d\n", x, y);
	fflush(stdout);
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int mn, mx;
		if(n & 1) mn = mx = n;
		else {
			if(ask(n-1, n) == -1) mn = n - 1, mx = n;
			else mn = n, mx = n - 1;
		}
		int tmp = n - 2 + (n & 1);
		for(int i=tmp;i>=1;i-=2) {
			int tmpp = ask(i-1, i), mxx = 0, mnn = 0;
			if(tmpp == -1) mnn = i - 1, mxx = i;
			else mnn = i, mxx = i - 1;
			if(ask(mnn, mn) == -1) mn = mnn;
			if(ask(mxx, mx) == 1) mx = mxx;
		}
		give(mn, mx);
	}
	return 0;
}