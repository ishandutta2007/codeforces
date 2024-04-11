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

int a[1005], t[1005], h;

bool check(int len){
	// printf("check %d\n", len);
	int H = h;
	for(int i=1; i<=len; i++) a[i] = t[i];
	sort(a+1, a+1+len);
	for(int i=len; i>=1; i-=2)
		if(H >= a[i]) H -= a[i];
		else return false;
	return true;
}

int main(){
	// File("b");
	int n, ans = 0;
	in(n); in(h);
	for(int i=1; i<=n; i++) in(t[i]);
	int l = 1, r = n, mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}