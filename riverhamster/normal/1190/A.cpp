#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int M = 100005;
ll a[M];

int main(){
	// File("a");
	ll n, m, k;
	ll d = 0, p, ni, res = 0;
	in(n); in(m); in(k);
	for(ll i=1; i<=m; i++) in(a[i]);
	for(ll i=1; i<=m; ){
		p = (a[i] - d) % k;
		if(p == 0) p = k;
		ni = i+1;
		// printf("max remove: %lld\n", a[i] + k - p);
		while(a[ni] - a[i] <= k - p && ni != m+1) ++ni;
		d += ni - i; i = ni; ++res;
		// printf("i = %d\n", i);
	}
	printf("%lld\n", res);
	return 0;
}