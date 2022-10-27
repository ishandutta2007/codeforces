#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
struct P {
	int x, y;
	void read() {
		scanf("%d%d",&x,&y);
	}
} p[4], pnt[4];
LL d(LL x,LL y,LL pos){
	return abs(pos-x) + abs(pos-y);
}
LL dd(LL l1,LL r1,LL l2,LL r2,LL l3,LL r3){
	return min(d(l1,r1,l3) + d(l2,r2,r3), d(l1,r1,r3) + d(l2,r2,l3));
}
LL solve(LL l1,LL r1,LL l2,LL r2,LL d) {
	if(l1>r1) swap(l1,r1);

	if(l2>r2) swap(l2,r2);
	
	if (l1>l2) {
		swap(l1,l2); swap(r1,r2);
	}

	LL ans = 1e18;
	if(r1<l2) {
		LL t=r1-l1+r2-l2;
		if(d<l2-r1){
			return t+(l2-r1-d)*2;
		}else if(d<=r2-l1){
			return t;
		}else{
			return t + 2*(d-(r2-l1));
		}
	}else if(r1<=r2){
		LL t=r1-l1+r2-l2;
		if(d<=r2-l1)return t;
		return t + 2*(d-(r2-l1));
	}else{
		LL t=r1-l1+r2-l2;
		LL lim=max(r2-l1,r1-l2);
		if(d<=lim) return t;
		return t+(d-lim) * 2;
	}
}

LL cal(LL d) {
	return solve(pnt[0].x, pnt[1].x, pnt[2].x, pnt[3].x, d) + solve(pnt[0].y,pnt[3].y,pnt[1].y,pnt[2].y, d);
}
int main() {
	//cout<<solve(5,6,1,2,3)<<endl; return 0;
	scanf("%d", &t);
	while (t --) {
		for(int i=0;i<4;i++){
			p[i].read();
		}
		LL res = 1e18;
		int perm[4] = {0,1,2,3};
		do {
			if(perm[0] == 0) {
				for(int i=0;i<4;i++) pnt[perm[i]] = p[i];
				
				int l = 0, r = 1e9;
				while (r - l > 8) {
					int midl = (l+r)>>1;
					int midr = (midl + r)>>1;
					if (cal(midl) < cal(midr)) {
						r = midr;
					} else {
						l = midl;
					}
				}

				
				LL ans = 1e18;
				//printf("[%d,%d]\n", l,r);
				
				for (int i = l; i <= r; i ++) {
					ans = min(ans, cal(i));
				}
				res = min(res, ans);
			}
			
			//cout << cal(3) << endl;
			//return 0;
		} while(next_permutation(perm, perm + 4));
		printf("%lld\n", res);

	}
}