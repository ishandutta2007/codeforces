#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,v;
	scanf("%d%d",&n,&v);
	if(v>n-1){
		v=n-1;
	}
	int ans=0;
	int now=0;
	for(int i=1;i<n;i++){
		if(now<n-i){
			ans+=(v-now)*i;
			now=v;
		}
		now--;
	}
	printf("%d\n",ans);
	return 0;
}