#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
unordered_map<ll, ll> m;
ll a[N];

int main(){
	// File("b");
	int n;
	ll p, k, ans = 0, x;
	in(n); in(p); in(k);
	for(int i=1; i<=n; i++) in(x), m[(x*x%p*x%p*x%p - x*k%p + p) % p]++;
	unordered_map<ll, ll>::iterator it;
	for(it = m.begin(); it != m.end(); ++it)
		ans += (it->second) * (it->second - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}