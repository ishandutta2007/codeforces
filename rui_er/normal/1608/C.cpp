//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, ans[N];
set<int> s;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int x, id;
	Node(int a=0, int b=0) : x(a), id(b) {}
	friend bool operator < (const Node& a, const Node& b) {
		return a.x < b.x;
	}
}a[N], b[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i].x), a[i].id = i;
		rep(i, 1, n) scanf("%d", &b[i].x), b[i].id = i;
		rep(i, 1, n) ans[i] = 0; s.clear();
		sort(a+1, a+1+n); sort(b+1, b+1+n);
		per(i, n, 1) {
			s.insert(a[i].id);
			s.insert(b[i].id);
			ans[a[i].id] = ans[b[i].id] = 1;
			if((int)s.size() <= n - i + 1) break;
		}
		rep(i, 1, n) putchar(ans[i] ^ 48);
		puts("");
	}
	return 0;
}