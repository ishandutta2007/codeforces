#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
int n,x,m;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&m);
		int l1=x,r1=x;
		for(int i=1;i<=m;i++){
			int l2,r2;scanf("%d%d",&l2,&r2);
			if(max(l1,l2)<=min(r1,r2)){
				l1=min(l1,l2), r1=max(r1,r2);
			}
		}
		printf("%d\n", r1-l1+1);
	}
}