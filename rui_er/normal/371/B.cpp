//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int a, b, gcd, ans;
int div1(int &x, int y) {int res = 0; while(!(x % y)) x /= y, ++res; return res;}

int main() {
	scanf("%d%d", &a, &b); gcd = __gcd(a, b); a /= gcd; b /= gcd;
	ans = div1(a, 2) + div1(a, 3) + div1(a, 5) + div1(b, 2) + div1(b, 3) + div1(b, 5);
	if(a == b) printf("%d\n", ans);
	else puts("-1");
	return 0;
}