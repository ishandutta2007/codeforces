#include <bits/stdc++.h>

const int max_N = 1e5 + 21;

int n,U,e[max_N];

double ans;

int main(){
	scanf("%d%d",&n,&U);
	for(int i=1;i<=n;++i)scanf("%d",e+i);
	for(int i=1,k=1;i<=n+2;++i){
		while(k<n&&e[k+1]-e[i]<=U)++k;
		if(k>=i+2)ans=std::max(ans,1.*(e[k]-e[i+1])/(e[k]-e[i]));
	}
	if(ans>1e-12)printf("%.15f\n",ans);
	else puts("-1");
	return 0;
}