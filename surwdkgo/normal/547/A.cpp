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
void lemon() {  
	int m;
	int h[2],a[2],x[2],y[2];
	scanf("%d",&m);
	rep(it,0,1) scanf("%d%d%d%d",&h[it],&a[it],&x[it],&y[it]);
	LL ans=-1;
	LL c;
	vector<int> v;
	LL d[2], l[2];
	rep(it,0,1) {
		v.clear();
		c = h[it];
		rep(t,0,m*3) {
			if (c == a[it]) {
				v.push_back(t);
				if (v.size() == 2) break;
			}
			c = ((LL)c *x[it] + y[it]) % m; 
		}
		if (v.size() == 0) {
			puts("-1");
			return;
		} else if (v.size() == 1) {
			l[it] = -1;
			d[it] = v[0];
		} else {
			d[it] = v[0];
			l[it] = v[1]-v[0];
		}
	}
	if (l[0] == -1 && l[1] != -1) {
		swap(l[0],l[1]);
		swap(d[0],d[1]);
	}
	if (l[0] == -1 && l[1] == -1) {
		if (d[0] == d[1]) ans = d[0]; 
	} else if (l[0] != -1 && l[1] == -1) {
		c = d[0];
		rep(j,0,m) {
			if (c == d[1]) ans = c;
			c = c + l[0];
		}
	} else {
		if (d[0] < d[1]) {
			swap(l[0],l[1]);
			swap(d[0],d[1]);
		}
		c = d[0];
		rep(j,0,m) {
			if (c % l[1] == d[1] % l[1]) {
				ans = c;
				break;
			}
			c = c + l[0];
		}
	}
	cout << ans << std::endl;
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
  #endif
  lemon();
  return 0;
}