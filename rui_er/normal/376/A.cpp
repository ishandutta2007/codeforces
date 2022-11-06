//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e6+5;

char s[N];
ll n, pos, lsum, rsum;

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	rep(i, 1, n) if(s[i] == '^') {pos = i; break;}
	rep(i, 1, pos-1) if(isdigit(s[i])) lsum += (s[i] ^ 48) * (pos - i);
	rep(i, pos+1, n) if(isdigit(s[i])) rsum += (s[i] ^ 48) * (i - pos);
	if(lsum == rsum) puts("balance");
	else if(lsum < rsum) puts("right");
	else puts("left");
	return 0;
}