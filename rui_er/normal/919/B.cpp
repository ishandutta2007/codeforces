//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int k, ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int x) {
	int s = 0;
	while(x) {
		s += x % 10;
		x /= 10;
	}
	return s == 10;
}

int main() {
	scanf("%d", &k);
	while(k) {
		if(check(++ans)) {
			--k;
			if(!k) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}