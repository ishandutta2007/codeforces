//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e6+5;

int T, n, ans[N]; ll sum;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int tms, id;
	Node(int a=0, int b=0) : tms(a), id(b) {}
	~Node() {}
	friend bool operator < (const Node& a, const Node& b) {
		return a.tms > b.tms;
	}
}a[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i].tms);
			a[i].id = i;
		}
		sort(a+1, a+1+n);
		int L = -1, R = 1;
		sum = 0;
		rep(i, 1, n) {
			if(i & 1) ans[a[i].id] = L--;
			else ans[a[i].id] = R++;
			sum += 2LL * abs(ans[a[i].id]) * a[i].tms;
		}
		printf("%lld\n", sum);
		printf("0 ");
		rep(i, 1, n) printf("%d%c", ans[i], " \n"[i==n]);
	}
    return 0;
}