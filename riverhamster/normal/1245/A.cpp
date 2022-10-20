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

int main(){
	// File("a");
	int T;
	in(T);
	while(T--){
		int a, b;
		in(a); in(b);
		int t;
		while(b) t = a, a = b, b = t % b;
		if(a == 1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}