#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
int n;
int inp[200010];
int ans[200010];
int fl;
int sor[200010];
multiset<int> in, le;
typedef multiset<int>::iterator IT;

bool cmp(int a, int b) {
	return inp[a] < inp[b];
}
void lemon() {  
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&inp[i]),sor[i]=i;
	fl = n;
	sort(sor+1,sor+n+1, cmp);
	in.insert(0);
	in.insert(n+1);
	le.insert(n);
	rep(i,1,n) {
		IT s = in.lower_bound(sor[i]);
		IT f = s;
		--f;
		int v1 = *f, v2 = *s;
		IT t = le.find(v2-v1-1);
		le.erase(t);
		in.insert(sor[i]);
		le.insert(v2-sor[i]-1);
		le.insert(sor[i]-v1-1);
		//printf("S: ");
		//rept(it,le) printf("%d ", *it);
		//puts("");
		int nv = *--le.end();
		//printf("%d %d %d %d\n", i, nv, sor[i], inp[sor[i]]);
		repd(j,fl,nv+1) ans[j] = inp[sor[i]];
		fl = nv;
	}
	rep(i,1,n) printf("%d%c", ans[i], " \n"[i==n]);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
  #endif
  lemon();
  return 0;
}