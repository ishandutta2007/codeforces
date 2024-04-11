#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200005;
long long f[N][3], c[3];
const int mod = 1000000007;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	int n, l, r;
	in(n); in(l); in(r);
	f[0][0] = 1;
	c[0] = (r / 3) - (l-1) / 3;
	c[1] = (r + 2) / 3 - (l + 1) / 3;
	c[2] = (r + 1) / 3 - l / 3;
	for(int i=1; i<=n; i++)
		for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				f[i][j] = (f[i][j] + f[i-1][k] * c[(j + 3 - k) % 3]) % mod;
	printf("%lld\n", f[n][0]);
	return 0;
}