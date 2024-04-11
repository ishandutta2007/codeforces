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
int inp[1000010];
void lemon() {  
	scanf("%d",&n);
	rep(i,0,n-1) {
		scanf("%d",&inp[i]);
		inp[i] += i;
	}
	std::sort(inp,inp+n);
	rep(i,0,n-2) {
		if (inp[i+1] == inp[i]) {
			puts(":(");
			return;
		}
	}
	rep(i,0,n-1) {
		printf("%d%c", inp[i]-i, " \n"[i==n-1]);
	}
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}