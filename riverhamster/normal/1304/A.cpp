#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

int main(){
	// File("a");
	int T;
	gi(T);
	while(T--){
		int l, r, x, y;
		gi(l); gi(r); gi(x); gi(y);
		if((r - l) % (x + y) == 0) printf("%d\n", (r - l) / (x + y));
		else puts("-1");
	}
	return 0;
}