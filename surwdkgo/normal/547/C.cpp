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
int n,q;
int h[200010];
int in[200010];
int cn;
int cnt[500010];
int w[500010];
LL ans;

void proc(int v, int d) {
	ans -= (LL) w[v] * cnt[v] * (cnt[v]-1) / 2;
	cnt[v]+=d;
	ans += (LL) w[v] * cnt[v] * (cnt[v]-1) / 2;
}

void up(int v, int d) {
	for(int i=1; i*i<=v; i++) {
		if (v%i ==0) {
			proc(i,d);
			if (i != v/i) proc(v/i,d);
		}
	}
}

void lemon() {
	rep(i,2,500000) {
		int cu = i;
		int fl = 0;
		for(int j=2; j*j<=cu; j++) {
			if (cu % j == 0) {
				fl = 1;
				if (cu % (j*j) == 0) w[i] = 0;
				else w[i] = -w[i/j];
				break;
			}
		}
		if (!fl) w[i] = 1;
		//if (i<10) printf("%d\n", w[i]);
	}  
	scanf("%d%d",&n,&q);
	rep(i,1,n) scanf("%d",&h[i]);
	rep(i,0,q-1) {
		int id;
		scanf("%d",&id);
		if (in[id]) {
			in[id] = 0;
			up(h[id],-1);
			cn--;
		} else {
			in[id] = 1;
			up(h[id],1);
			cn++;
		}
		cout << (LL) cn * (cn-1)/2-ans << endl;
	}
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
  #endif
  lemon();
  return 0;
}