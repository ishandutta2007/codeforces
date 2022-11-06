//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 205;

int n, x, X;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%s", &n, s+1);
	rep(i, 1, n) {
		if(s[i] == 'x') ++x;
		else ++X;
	}
	if(x == X) printf("0\n%s\n", s+1);
	else if(x < X) {
		int nd = (X - x) / 2;
		printf("%d\n", nd);
		rep(i, 1, n) {
			if(s[i] == 'X') {
				s[i] = 'x';
				--nd;
				if(!nd) break;
			}
		}
		puts(s+1);
	}
	else {
		int nd = (x - X) / 2;
		printf("%d\n", nd);
		rep(i, 1, n) {
			if(s[i] == 'x') {
				s[i] = 'X';
				--nd;
				if(!nd) break;
			}
		}
		puts(s+1);
	}
	return 0;
}