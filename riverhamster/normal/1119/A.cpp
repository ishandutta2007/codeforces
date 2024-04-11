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

const int N = 300005;
int a[N];

int main(){
	// File("a");
	int n;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	if(a[1] != a[n]) printf("%d\n", n-1);
	else{
		int bg = 1, ed = n;
		for(int i=2; i<=n; i++) if(a[i] != a[1]){
			bg = i; break;
		}
		for(int i=n; i>=2; i--){
			if(a[i] != a[n]){
				ed = i; break;
			}
		}
		printf("%d\n", max(n - bg, ed-1));
	}
	return 0;
}