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
	int b, k, now = 1, ans = 0;
	in(b); in(k);
	for(int i=k-1; i>=0; i--) in(a[i]);
	for(int i=0; i<k; i++){
		ans += now * a[i]; ans = ans & 1;
		now *= b; now &= 1;
	}
	if(ans) puts("odd");
	else puts("even");
	return 0;
}