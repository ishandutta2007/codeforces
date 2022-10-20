#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
ll X1, Y1, X2, Y2, n, sx[100005], sy[100005];
char s[100005];

bool check(ll d){
	ll mx = (d / n) * sx[n] + sx[d % n];
	ll my = (d / n) * sy[n] + sy[d % n];
	return abs(mx + X1 - X2) + abs(my + Y1 - Y2) <= d;
}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	in(X1); in(Y1); in(X2); in(Y2);
	in(n);
	scanf("%s", s+1);
	for(int i=1; i<=n; i++){
		switch(s[i]){
			case 'U': s[i] = 0; break;
			case 'D': s[i] = 1; break;
			case 'L': s[i] = 2; break;
			case 'R': s[i] = 3; break;
		}
		sx[i] = sx[i-1] + dx[(int)s[i]];
		sy[i] = sy[i-1] + dy[(int)s[i]];
	}
	ll l = 0, r = 4000000000000000000LL, mid, ans = -1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid +1;
	}
	printf("%lld\n", ans);
	return 0;
}