#include<bits/stdc++.h>
using namespace std;
int T,n,mx,mn,mxd,mnd,x,tp;
bool fl;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		mx=-1e9,mn=1e9;fl=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(fl)continue;
			tp=x-i+1;
			if(tp<mn)mn=tp,mnd=i;
			tp=x+i-1;
			if(tp>mx)mx=tp,mxd=i;
			if(x-i>=mn){
				printf("YES\n%d %d\n",mnd,i);
				fl=1;
			}
			else if(x+i<=mx){
				printf("YES\n%d %d\n",mxd,i);
				fl=1;
			}
		}
		if(!fl)puts("NO");
	}
}