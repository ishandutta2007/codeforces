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

long long a[200005];

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	long long n, m, k;
	long long ans = 0;
	in(n); in(m); in(k);
	for(int i=1; i<=n; i++) in(a[i]);
	sort(a+1, a+1+n);
	ans = (m / (k + 1)) * (a[n] * k + a[n-1]) + (m % (k+1)) * a[n];
	printf("%lld\n", ans);
	return 0;
}