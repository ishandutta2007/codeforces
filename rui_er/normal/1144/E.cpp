//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], len;
char s[N], t[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void add() {
	int carry = 0;
	len = n;
	rep(i, 1, n) {
		a[i] = s[i] - 'a' + t[i] - 'a' + carry;
		carry = a[i] / 26;
		a[i] %= 26;
	}
	if(carry) a[++len] = carry;
}
void div2() {
	int carry = 0;
	rep(i, 1, len) {
		a[i] = carry * 26 + a[i];
		carry = a[i] & 1;
		a[i] >>= 1;
	}
}

int main() {
	scanf("%d%s%s", &n, s+1, t+1);
	reverse(s+1, s+1+n);
	reverse(t+1, t+1+n);
	add();
	reverse(a+1, a+1+len);
	div2();
	rep(i, len-n+1, len) printf("%c", a[i]+'a');
	puts("");
	return 0;
}