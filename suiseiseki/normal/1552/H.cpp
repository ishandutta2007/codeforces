#include <cstdio>
#include <algorithm>
int S,T,TS;
int query(int d){
	printf("? %d\n",(200/d)*200);
	for(int i=d;i<=200;i+=d){
		for(int j=1;j<=200;j++){
			printf("%d %d ",i,j);
		}
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	S=query(1);
	int left=1,right=7;
	while(left<=right){
		int mid=(left+right)>>1;
		int d=(1<<mid);
		T=query(d);
		if(d*T==S){
			left=mid+1;
		}
		else{
			TS=T;
			right=mid-1;
		}
	}
	left--;
	int h=std::abs(2*TS-S/(1<<left));
	printf("! %d\n",2*(h-1+S/h-1));
	return 0;
}