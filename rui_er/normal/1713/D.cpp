// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/D
// Memory Limit: 256 MB
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
const int N = 1 << 17 | 5;

int T, n, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
void give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int k = 1 << n;
		rep(i, 1, k) a[i] = i;
		while(k >= 4) {
			for(int i=1;i<=k;i+=4) {
				int qwq = ask(a[i], a[i+2]);
				if(qwq == 1) {
					int qaq = ask(a[i], a[i+3]);
					if(qaq == 1) b[i/4+1] = a[i];
					else b[i/4+1] = a[i+3];
				}
				else if(qwq == 2) {
					int qaq = ask(a[i+1], a[i+2]);
					if(qaq == 1) b[i/4+1] = a[i+1];
					else b[i/4+1] = a[i+2];
				}
				else {
					int qaq = ask(a[i+1], a[i+3]);
					if(qaq == 1) b[i/4+1] = a[i+1];
					else b[i/4+1] = a[i+3];
				}
			}
			rep(i, 1, k/4) a[i] = b[i];
			k /= 4;
		}
		if(k == 2) {
			int qwq = ask(a[1], a[2]);
			if(qwq == 2) swap(a[1], a[2]);
		}
		give(a[1]);
	}
	return 0;
}