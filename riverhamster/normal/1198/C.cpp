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
const int N = 300005;
bool vis[N];
int e[N], ec = 0;

int main(){
	// File("c");
	int T, x, y, n, m;
	in(T);
	while(T--){
		ec = 0;
		in(n); in(m);
		for(int i=1; i<=n*3; i++) vis[i] = false;
		for(int i=1; i<=m; i++){
			in(x); in(y);
			if(!vis[x] && !vis[y]){
				vis[x] = vis[y] = true;
				e[++ec] = i;
			}
		}
		if(ec >= n){
			puts("Matching");
			for(int i=1; i<=n; i++) printf("%d ", e[i]);
			putchar('\n');
		}
		else{
			puts("IndSet");
			int cnt = 0;
			for(int i=1; i<=3*n; i++)
				if(!vis[i]){
					++cnt; printf("%d ", i);
					if(cnt == n) break;
				}
			putchar('\n');
		}
	}
	return 0;
}