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
const int N = 400005;
int a[N], c[N], sl[N], sr[N];

int main(){
	// File("a");
	int n, m, cnt = 0, p;
	in(n); in(m); m = m * 8 / n;
	for(int i=1; i<=n; i++) in(a[i]);
	sort(a+1, a+1+n);
	a[0] = -1;
	for(int i=1; i<=n; i++){
		if(a[i] == a[i-1]) ++c[cnt];
		else c[++cnt] = 1;
	}
	// for(int i=1; i<=cnt; i++) printf("%d ", c[i]);
	// puts("");
	if(m > 29){
		puts("0"); return 0;
	}
	p = 1 << m; p = cnt - p;
	if(p <= 0){
		puts("0"); return 0;
	}
	// printf("p = %d\n", p);
	int ans = 0x7fffffff;
	for(int i=1; i<=cnt; i++) sl[i] = sl[i-1] + c[i];
	for(int i=cnt; i>=1; i--) sr[i] = sr[i+1] + c[i];
	for(int i=0; i<=p; i++)
		ans = min(ans, sl[i] +sr[cnt - (p - i) + 1]);//, printf("%d + %d\n", i, cnt - (p - i));
	printf("%d\n", ans);
	return 0;
}