#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
int ans[1000];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	INT p,d;
	scanf("%I64d%I64d",&p,&d);
	int cnt=0;
	while(p){
		int r=p%10;
		if(r==9){
			ans[cnt++]=9;
			p/=10;
			d/=10;
			continue;
		}
		if(r<9){
			int x=r+1;
			if(x>d) break;
			ans[cnt++]=9;
			p-=x;
			d-=x;
			p/=10;
			d/=10;
		}
	}
	if(p) printf("%I64d",p);
	for(int i=cnt-1;i>=0;i--) printf("%d",ans[i]);
	return 0;
}