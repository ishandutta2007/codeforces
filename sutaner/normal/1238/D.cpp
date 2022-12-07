#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 400019
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n;
char s[maxn];

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	ll ans = (ll)n * (n + 1) / 2;
	ans -= n;
	int last = 0;
	rep(i, 1, n){
		ans -= last;
		int now = s[i], _i = i;
		while (i <= n && s[i] == now) i++; 
		last = i - _i;
		i--;
	}
	last = 0;
	per(i, n, 1){
		if (i == n) ans -= (n - i);
		else ans -= (last - 1);
		int now = s[i], _i = i;
		while (i >= 1 && s[i] == now) i--; 
		last = _i - i;
		i++;
	}
	printf("%lld", ans);
	return 0;
}