//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int n, m, a, b, veryImportantVariable;

int main() {
	scanf("%d%d", &n, &m);
	if(n < m) return puts("0/1"), 0;
	scanf("%d", &a); rep(i, 1, n) scanf("%d", &veryImportantVariable);
	scanf("%d", &b); rep(i, 1, m) scanf("%d", &veryImportantVariable);
	if(a * b < 0) a = abs(a), b = abs(b), putchar('-');
	if(n > m) return puts("Infinity"), 0;
	int qwq = __gcd(a, b); a /= qwq; b /= qwq;
	printf("%d/%d\n", a, b);
	return 0;
}