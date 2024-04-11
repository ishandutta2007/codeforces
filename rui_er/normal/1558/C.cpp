//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2025;

int T, n, a[N];
vector<int> ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void rev(int x) {
	if(x == 1) return;
	if(!(x & 1)) exit(1);
	reverse(a+1, a+1+x);
	ans.push_back(x);
//	rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
}
int find(int x) {
	rep(i, 1, n) if(a[i] == x) return i;
	return 0;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int ok = 1;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if((a[i] & 1) != (i & 1)) ok = 0;
		}
		if(!ok) {puts("-1"); continue;}
		ans.clear();
		for(int i=n;i>=1;i-=2) {
//			int now = find(i);
//			rev(now); rev(i); // WA on Pretest 2 let's forget it :(
			// 5n/2 <=> 5 operations to sort 2 elements?
			int now = find(i);
			rev(now); // reverse i to 1
			now = find(i-1);
			rev(now-1); rev(now+1); // reverse i, i-1 to 3, 2
			rev(3); // reverse i, i-1 to 1, 2
			rev(i); // reverse i, i-1 to i, i-1
			if(is_sorted(a+1, a+1+n)) break; // check if already sorted
		}
		int sz = ans.size();
		printf("%d\n", sz);
		rep(i, 0, sz-1) printf("%d%c", ans[i], " \n"[i==sz-1]);
	}
	return 0;
}
/*
3 4 7 2 5 6 1
7 4 3 2 5 6 1
5 2 3 4 7 6 1
1 6 7 4 3 2 5
7 6 1 4 3 2 5
5 2 3 4 1[6 7]
5 2 3 4 1[6 7]
3 2 5 4 1[6 7]
1 4 5 2 3[6 7]
5 4 1 2 3[6 7]
3 2 1[4 5 6 7]
[1 2 3 4 5 6 7]
*/