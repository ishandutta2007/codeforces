#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 200005, inf = 1000000001;
int n, a[N];

int main(){
	// File("b");
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	ll ans = a[n];
	int last = a[n];
	for(int i=n-1; i>=1; i--){
		if(last == 0) break;
		ans += min(a[i], last - 1);
		last = min(a[i], last - 1);
	}
	printf("%lld\n", ans);
	return 0;
}