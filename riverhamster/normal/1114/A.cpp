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
	int x, y, z, a, b, c;
	in(x); in(y); in(z); in(a); in(b); in(c);
	if(x > a){
		puts("NO"); return 0;
	}
	if(y > a + b - x){
		puts("NO"); return 0;
	}
	if(z > a + b + c - x - y){puts("NO"); return 0;}
	else puts("YES");
	return 0;
}