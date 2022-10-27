#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int leaf=1,now=2,dep=0;

		while(now<=n){
			int nex_leaf=0;
			++dep;
			for(int i=1;i<=leaf;i++){
				int r=now;
				while(r<=n && (r==now||a[r]>=a[r-1])) ++r;
				nex_leaf+=r-now;
				//printf("[%d,%d)\n", now,r);
				now=r;
				if(now>n) break;
			}
			leaf=nex_leaf;
		}
		printf("%d\n", dep);
	}
}