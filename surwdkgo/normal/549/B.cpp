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
int inp[110][110];
int goa[110];
int deg[110];
int usd[110];
void lemon() {
	scanf("%d",&n);
	rep(i,0,n-1) {
		char tmp[110];
		scanf("%s",tmp);
		rep(j,0,n-1) {
			inp[i][j] = tmp[j] - '0';
			deg[j] += inp[i][j];
		}
	}  
	rep(i,0,n-1) scanf("%d",&goa[i]);
	rep(itr,0,n) {
		int fl = 0;
		int cs;
		rep(i,0,n-1) {
			if (deg[i] == goa[i]) fl = 1,cs=i;
		}
		if (!fl) {
			int fir = 1;
			printf("%d",n-itr);
			rep(i,0,n-1) {
				if (!usd[i]) {
					printf("%c%d",fir?'\n':' ',i+1); fir = 0;
				}
			}
			puts("");
			return;
		}
		usd[cs] = 1;
		rep(i,0,n-1) deg[i] -= inp[cs][i];

	}

}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
   // freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}