//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], buc[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
vector<int> x, y;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(++buc[a[i]] > 2) return puts("NO")&0;
	}
	rep(i, 0, 200000) if(buc[i]) {x.push_back(i); --buc[i];}
	per(i, 200000, 0) if(buc[i]) {y.push_back(i); --buc[i];}
	int sz1 = x.size(), sz2 = y.size();
	printf("YES\n%d\n", sz1);
	rep(i, 0, sz1-1) printf("%d ", x[i]); puts("");
	printf("%d\n", sz2);
	rep(i, 0, sz2-1) printf("%d ", y[i]); puts("");
	return 0;
}