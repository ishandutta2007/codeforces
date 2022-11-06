//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 505;

int T, n, a[N], b[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
map<pair<int, int>, int> mp;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		if((n & 1) && a[(n+1)/2] != b[(n+1)/2]) {puts("NO"); continue;}
		mp.clear();
		int ok = 1;
		rep(i, 1, n/2) {
			if(a[i] > a[n-i+1]) swap(a[i], a[n-i+1]);
			if(b[i] > b[n-i+1]) swap(b[i], b[n-i+1]);
		}
		rep(i, 1, n/2) ++mp[make_pair(a[i], a[n-i+1])];
		rep(i, 1, n/2) {
			if(!mp[make_pair(b[i], b[n-i+1])]) {ok = 0; break;}
			--mp[make_pair(b[i], b[n-i+1])]; 
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}