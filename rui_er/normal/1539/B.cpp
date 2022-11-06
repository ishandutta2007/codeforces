//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, q, a[N], s[N];
char c[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%s", &n, &q, c+1);
	rep(i, 1, n) {
		a[i] = c[i] - 'a' + 1;
		s[i] = s[i-1] + a[i];
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r]-s[l-1]);
	}
	return 0;
}