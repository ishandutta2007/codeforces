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
const int N = 505;
int a[N][N];
int sl[N], sc[N];

int main(){
	// File("c");
	int n, m, x;
	in(n); in(m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			in(a[i][j]);
		}
	// int s;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			in(x);
			sl[i] ^= (a[i][j] ^ x);
			sc[j] ^= (a[i][j] ^ x);
		}
	}
	for(int i=1; i<=m; i++) if(sc[i]){
		puts("No");
		return 0;
	}
	for(int i=1; i<=n; i++) if(sl[i]){
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}