#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
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
ll f[N];

int main(){
	// File("e");
	int n;
	ll s = 0, x, sp;
	in(n);
	for(int i=1; i<=n; i++){
		in(x);
		sp = s - 3 * f[i-1];
		if(sp * 2 >= x) f[i] = f[i-1] + x / 2;
		else f[i] = f[i-1] + (x - sp * 2) / 3 + sp;
		s += x;
	}
	printf("%lld\n", f[n]);
	return 0;
}