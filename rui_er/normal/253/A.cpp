//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 205;

int n, m;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n <= m) {
		rep(i, 1, n) {
			s[2*i-1] = 'G';
			s[2*i] = 'B';
		}
		rep(i, 2*n+1, n+m) s[i] = 'G';
	}
	else {
		rep(i, 1, m) {
			s[2*i-1] = 'B';
			s[2*i] = 'G';
		}
		rep(i, 2*m+1, n+m) s[i] = 'B';
	}
	s[n+m+1] = '\0';
	puts(s+1);
	return 0;
}