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
int a[100005], l[100005];

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	int n, m, k;
	in(n); in(m); in(k);
	for(int i=1; i<=n; i++){
		in(a[i]);
		if(i != 1) l[i-1] = a[i] - a[i-1] - 1;
	}
	sort(l+1, l+n);
	int ans = 0;
	for(int i=1; i+k<=n; i++)
		ans += l[i];
	printf("%d\n", ans + n);
	return 0;
}