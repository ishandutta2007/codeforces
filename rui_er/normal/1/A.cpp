//By: Luogu@rui_er(122461)qwqwq
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

ll n, m, a; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld%lld", &n, &m, &a);
	printf("%lld\n", (n/a+!!(n%a))*(m/a+!!(m%a)));
	return 0;
}