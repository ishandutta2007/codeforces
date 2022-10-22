#include<bits/stdc++.h>
using namespace std;
int n,x[1005],y[1005],a[2][2];
int calc(){
	return (a[0][0]>0)+(a[1][0]>0)+(a[1][1]>0)+(a[0][1]>0);
}
int main(){
	scanf("%d",&n);
	bool flag=0;
	int py=1000000;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=py;y[i]+=py;
	}
	do{
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				a[i][j]=0;
		for(int i=1;i<=n;++i){
			if(flag)x[i]>>=1,y[i]>>=1;
			a[x[i]&1][y[i]&1]++;
		}
		flag=1;
	}while(calc()==1);
	if(calc()==2){
		bool ok=0;
		for(int i=0;i<2&&!ok;++i)
			for(int j=0;j<2;++j){
				if(a[i][j]){
					ok=1;
					printf("%d\n",a[i][j]);
					for(int k=1;k<=n;++k)
						if((x[k]&1)==i&&(y[k]&1)==j){
							printf("%d ",k);
						}	
					break;
				}
			}
	}
	else{
		printf("%d\n",a[0][0]+a[1][1]);
		for(int i=1;i<=n;++i){
			if(!((x[i]&1)^(y[i]&1)))printf("%d ",i);
		//	cerr<<i<<": "<<x[i]<<" "<<y[i]<<endl;
		}
	}	
	return 0;
}