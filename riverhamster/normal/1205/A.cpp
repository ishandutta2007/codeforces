#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int a[200005];

int main(){
	// File("a");
	int n;
	in(n);
	if(n & 1){
		puts("YES");
		for(int i=1; i<=n; i++)
			if(i & 1) a[i] = i*2-1, a[i+n] = i*2;
			else a[i] = i*2, a[i+n] = i*2-1;
		
		for(int i=1; i<=2*n; i++) printf("%d ", a[i]);
	}
	else puts("NO");
	return 0;
}