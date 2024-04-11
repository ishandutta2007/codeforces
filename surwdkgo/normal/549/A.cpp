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
int r,c;
char inp[100][100];
char cnt[300];
void lemon() {  
	scanf("%d%d",&r,&c);
	rep(i,0,r-1) scanf("%s", &inp[i]);
	int ans = 0;
	rep(i,0,r-2) {
		rep(j,0,c-2) {
			rep(k,0,1) {
				rep(l,0,1) {
					cnt[inp[i+k][j+l]]++;
				}
			}
			if (cnt['f'] == 1 && cnt['a'] == 1 && cnt['c'] == 1 && cnt['e'] == 1) ans ++;

			rep(k,0,1) {
				rep(l,0,1) {
					cnt[inp[i+k][j+l]]--;
				}
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("A.in","r",stdin);
  #endif
  lemon();
  return 0;
}