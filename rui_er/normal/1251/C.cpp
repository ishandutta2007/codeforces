//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5; 

int T, n;
char s[N];
queue<int> a[2], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		rep(i, 1, n) {
			int k = s[i] - '0';
			a[k&1].push(k);
		}
		while(!a[0].empty() || !a[1].empty()) {
			if(a[0].empty()) {ans.push(a[1].front()); a[1].pop();}
			else if(a[1].empty()) {ans.push(a[0].front()); a[0].pop();}
			else if(a[0].front() < a[1].front()) {ans.push(a[0].front()); a[0].pop();}
			else {ans.push(a[1].front()); a[1].pop();}
		}
		while(!ans.empty()) {printf("%d", ans.front()); ans.pop();}
		puts("");
	}
	return 0;
}