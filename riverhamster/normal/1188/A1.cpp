#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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
const int N = 200005;
int to[N], nt[N], hd[N], deg[N], tot = 0;
inline void addedge(int x, int y){
	++tot;
	to[tot] = y; nt[tot] = hd[x]; hd[x] = tot; ++deg[y];
}

int main(){
	// File("a");
	int n, x, y;
	in(n);
	for(int i=1; i<n; i++) in(x), in(y), addedge(x, y), addedge(y, x);
	for(int i=1; i<=n; i++) if(deg[i] == 2){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}