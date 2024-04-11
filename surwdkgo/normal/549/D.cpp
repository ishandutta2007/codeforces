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
int n,m;
char inp[210][211];
int cnt[210][210], goa[210][210];
void lemon() {  
	scanf("%d%d",&n,&m);
	rep(i,0,n-1) {
		scanf("%s", inp[i]);
		rep(j,0,m-1) goa[i][j] = inp[i][j] == 'W' ? 1 : -1; 
	}
	int ans=0;
	repd(i,n-1,0) {
		repd(j,m-1,0) {
			cnt[i][j] = cnt[i+1][j] + cnt[i][j+1] - cnt[i+1][j+1];
			if (cnt[i][j] != goa[i][j]) {
				ans ++;
				cnt[i][j] = goa[i][j];
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
 //   freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}