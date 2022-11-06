// Problem: Ex - Multiply or Divide by 2
// Contest: AtCoder - AtCoder Beginner Contest 254
// URL: https://atcoder.jp/contests/abc254/tasks/abc254_h
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n;
priority_queue<int> a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		while(!a.empty()) a.pop();
		while(!b.empty()) b.pop();
		scanf("%d", &n);
		rep(i, 1, n) {
			int x;
			scanf("%d", &x);
			b.push(x);
		}
		rep(i, 1, n) {
			int x;
			scanf("%d", &x);
			a.push(x);
		}
		while(!a.empty() && !b.empty()) {
			int u = a.top(), v = b.top();
			if(u == v) {a.pop(); b.pop();}
			else if(u > v) {
				a.pop();
				if(!u) {puts("NO"); goto end;}
				a.push(u/2);
			}
			else {
				b.pop();
				if(!v || v & 1) {puts("NO"); goto end;}
				b.push(v/2);
			}
		}
		puts("YES");
		end:;
	}
	return 0;
}