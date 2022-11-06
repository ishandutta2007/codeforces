//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], deg[N];
priority_queue<int> q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		scanf("%d", &a[i]);
		++deg[a[i]];
	}
	rep(i, 1, n) {
		if(!deg[i]) {
			q.push(-i);
		}
	}
	printf("%d\n", a[1]);
	per(i, n-1, 1) {
		if(q.empty()) throw 1;
		int u = -q.top(); q.pop();
		printf("%d %d\n", a[i], u);
		if(!--deg[a[i]]) q.push(-a[i]);
	}
	return 0;
}