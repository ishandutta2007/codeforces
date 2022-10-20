#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) stdin = freopen(s".in", "r", stdin), stdout = freopen(s".out", "w", stdout)
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
	// File("b");
	int T;
	in(T);
	while(T--){
		ll n, hp, mxdec = 0, mxatk = 0, dec, inc;
		in(n); in(hp);
		for(int i=1; i<=n; i++) in(dec), in(inc), mxdec = max(mxdec, dec), mxatk = max(mxatk, dec - inc);
		// printf("Mxdec = %d Mxatk = %d hp = %d\n", mxdec, mxatk, hp);
		if(hp <= mxdec) puts("1");
		else if(mxatk <= 0) puts("-1");
		else printf("%lld\n", (hp - mxdec - 1) / mxatk + 2);
	}
	return 0;
}