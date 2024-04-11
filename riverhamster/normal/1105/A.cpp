#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1005];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int n, now, ans = 0x7fffffff, anst;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	for(int i=1; i<=100; i++){
		now = 0;
		for(int j=1; j<=n; j++)
			if(a[j] > i) now += a[j] - (i + 1);
			else if(a[j] < i) now += (i-1) - a[j];
		if(now < ans) ans = now, anst = i;
	}
	printf("%d %d\n", anst, ans);
	return 0;
}