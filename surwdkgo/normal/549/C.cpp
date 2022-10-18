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
int n,k;
int c[2];
void lemon() {  
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		int t;
		scanf("%d",&t);
		c[t%2]++;
	}
	int ans;
	if (n == k) {
		if (c[1] % 2) ans = 1;
		else ans = 0;
	} else {
		if (n%2 == k%2) {
			// end with dany
			if (k % 2 == 0) ans = 0;
			else {
				// stan needs to end with all odd
				int ns = (n-k+1)/2;
				//printf("%d %d\n", ns, c[0]);
				if (ns >= c[0]) ans = 1;
				else ans = 0;
			}
		} else {
			// end with stan
			if (k % 2 == 0) {
				// dany needs to end with all odd or all even
				if (c[0] == c[1]) ans = 1;
				else {
					int nd = (n-k)/2;
					if (nd >= min(c[0],c[1])) ans = 0;
					else ans = 1;

				}
			} else {
				// dany needs to end with all even
				int nd = (n-k)/2;
				if (nd >= c[1]) ans = 0;
				else ans = 1;
			}
		}
	}
	puts(ans ? "Stannis" : "Daenerys");
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
   // freopen("C.in","r",stdin);
  #endif
  lemon();
  return 0;
}