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

int main(){
	// File("c");
	int n, m;
	ll ans = 4;
	in(n); in(m);
	for(int i=2; i<=n; i++) ans = (ans * 2) % 998244353;
	for(int i=2; i<=m; i++) ans = (ans * 2) % 998244353;
	printf("%lld\n", ans);
	return 0;
}