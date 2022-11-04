#include <cstdio>
#include <iostream>
using namespace std;

int q, n, m, pt, t, l, r, ll, rr;
bool flag;

int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &n, &m);
		ll = rr = m;
		pt = 0;
		flag = true;
		while(n--){
			scanf("%d%d%d", &t, &l, &r);
			int dt = t - pt;
			ll = max(ll - dt, l);
			rr = min(rr + dt, r);
			if(ll > rr) flag = false;
			pt = t;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}