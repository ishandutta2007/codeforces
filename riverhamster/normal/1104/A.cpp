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

int main(){
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for(int i=1; i<=n; i++) printf("1 ");
	return 0;
}