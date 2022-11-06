//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, x, a[N];
priority_queue<int> q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		while(!q.empty()) q.pop();
		scanf("%d%d", &n, &x);
		rep(i, 1, n) scanf("%d", &a[i]);
		if(x <= n / 2) puts("YES");
		else {
			int L = n - x + 1, R = x;
			rep(i, 1, L-1) q.push(-a[i]);
			rep(i, R+1, n) q.push(-a[i]);
			rep(i, 1, L-1) {
				a[i] = -q.top();
				q.pop();
			}
			rep(i, R+1, n) {
				a[i] = -q.top();
				q.pop();
			}
			if(is_sorted(a+1, a+1+n)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}