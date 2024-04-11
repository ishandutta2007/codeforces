#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
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

int a[100];
bool asked[10000005];

inline int gcd(int x, int y){
	int t;
	while(y!=0) t=x, x=y, y=t%y;
	return x;
}

int main(){
	mt19937 rnd(time(0));
	int n, x, askcnt = 0;
	scanf("%d", &n);
	int l = 1, r = 1000000000, mid, ans = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		printf("> %d\n", mid); fflush(stdout);
		scanf("%d", &x);
		if(x == -1) return 0;
		if(x == 0){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
		++askcnt;
	}
	int lim = min(n, 60-askcnt), ask;
	for(int i=1; i<=lim; i++){
		do ask = rnd() % n + 1; while(asked[ask]);
		asked[ask] = true;
		printf("? %d\n", ask); fflush(stdout);
		scanf("%d", &x);
		if(x == -1) return 0;
		a[i] = ans - x;
	}
	int res = a[1];
	for(int i=2; i<=lim; i++) res = gcd(res, a[i]);
	printf("! %d %d\n", ans - res * (n-1), res); fflush(stdout);
	return 0;
}