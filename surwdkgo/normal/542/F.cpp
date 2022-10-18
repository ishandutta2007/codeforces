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
int n,t;
multiset<int> abl[110];
void lemon() {
	scanf("%d%d", &n,&t);
	for (int i=0; i<n; i++) {
		int ct, cf;
		scanf("%d%d", &ct, &cf);
		abl[ct].insert(-cf);
	}  
	rep(i,1,t-1) {
		if (abl[i].size() == 0) continue;
		rept(it,abl[i]){
			typeof(it) it2 = it;
			++it2;
			if (it2 == abl[i].end()) abl[i+1].insert(*it);
			else {abl[i+1].insert(*it+*it2); it++;}
		}
	}
	printf("%d\n", -*abl[t].begin());
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
   // freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}