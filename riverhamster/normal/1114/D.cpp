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
const int N = 5005;
int a[N];
int f[N][N];

int main(){
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	int n;
	in(n);
	for(int i=1; i<=n; i++){
		in(a[i]);
		if(a[i] == a[i-1]) --n, --i;
	}
	// printf("n = %d\n", n);
	int j;
	for(int len=1; len<n; len++)
		for(int i=1; i<=n; i++){
			j = i + len;
			if(a[i] == a[j]) f[i][j] = f[i+1][j-1] + 1;
			else f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
			// printf("f[%d][%d] = %d\n", i, j, f[i][j]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}