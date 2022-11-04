#include <cstdio>
#include <iostream>
using namespace std;

int t, n, l, cl, r, cr, ll, rr, cc;
int singlec, singlel, singler;

int main(){
	scanf("%d", &t);
	while(t--){
		l = 1e9 + 1, r = 0;
		singlel = 1e9 + 1, singler = 0;
		scanf("%d", &n);
		while(n--){
			scanf("%d%d%d", &ll, &rr, &cc);
			if(ll <= singlel && rr >= singler){
				if(ll < singlel || rr > singler)
					singlec = cc;
				else
					singlec = min(cc, singlec);
				singlel = ll;
				singler = rr;
			}
			if(ll <= l){
				if(ll < l)
					cl = cc;
				else
					cl = min(cl, cc);
				l = ll;
			}
			if(rr >= r){
				if(rr > r)
					cr = cc;
				else
					cr = min(cr, cc);
				r = rr;
			}
			if(l == singlel && r == singler)
				printf("%d\n", min(singlec, cl + cr));
			else
				printf("%d\n", cl + cr);
		}
	}
	return 0;
}