#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) stdin = freopen(s".in", "r", stdin), stdout = freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// File("a");
	int T;
	in(T);
	while(T--){
		int x, y, z;
		in(x); in(y); in(z);
		if(x + z <= y){
			puts("0");
			continue;
		}
		int pmin = (y + z - x + 2) / 2;
		pmin = max(pmin, 0);
		// printf("pmin = %d\n", pmin);
		printf("%d\n", z - pmin + 1);
	}
	return 0;
}