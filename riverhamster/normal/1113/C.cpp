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
const int N = 300005;
int c[2][(1<<20) + 5];

int main(){
	// freopen("cf1113c.in", "r", stdin);
	// freopen("cf1113c.out", "w", stdout);
	int n, s = 0, x;
	long long ans = 0;
	in(n);
	++c[0][0];
	for(int i=1; i<=n; i++){
		in(x);
		s ^= x;
		ans += c[i&1][s];
		++c[i&1][s];
	}
	printf("%lld\n", ans);
	return 0;
}