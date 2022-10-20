#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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

char s[100005];

int main(){
	// File("a");
	int n;
	long long ans = 0;
	in(n);
	scanf("%s", s);
	for(int i=0; i<n; i++)
		if(((s[i] - '0') & 1) == 0) ans += i+1;
	printf("%lld\n", ans);
	return 0;
}