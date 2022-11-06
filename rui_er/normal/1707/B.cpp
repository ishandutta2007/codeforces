// Problem: B. Difference Array
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, a[N];
map<int, int> now, nxt;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		now.clear();
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			++now[a[i]];
		}
		rep(i, 1, n-1) {
			nxt.clear();
			for(auto it=now.begin();it!=now.end();it++) {
				if(it->second > 1) nxt[0] += it->second - 1;
			}
			auto lst = now.begin(), it = lst; ++it;
			for(;it!=now.end();it++,lst++) {
				int qwq = it->first - lst->first;
				++nxt[qwq];
			}
			swap(now, nxt);
		}
		printf("%d\n", now.begin()->first);
	}
	return 0;
}