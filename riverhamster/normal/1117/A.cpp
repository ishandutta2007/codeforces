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

int a[100005];

int main(){
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int n, mx = 0, len = 0, ans = 0;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]), mx = max(mx, a[i]);
	for(int i=1; i<=n; i++)
		if(a[i] == mx) ++len;
		else{
			ans = max(ans, len);
			len = 0;
		}
	ans = max(ans, len);
	printf("%d\n", ans);
	return 0;
}