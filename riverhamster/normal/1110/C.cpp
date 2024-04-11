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
inline int lb(int x){return x & -x;}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	int q, x, ans;
	in(q);
	while(q--){
		in(x);
		if(x + 1 == lb(x+1)){
			ans = 1;
			for(int i=2; i*i<=x; i++)
				if(x % i == 0){
					ans = x / i; break;
				}
			printf("%d\n", ans);
		}
		else{
			int now = 1;
			while(now < x){
				if((x & now) == 0) x |= now;
				// printf("x = %d now = %d\n", x, now);
				now <<= 1;
			}
			printf("%d\n", x);
		}
	}
	return 0;
}